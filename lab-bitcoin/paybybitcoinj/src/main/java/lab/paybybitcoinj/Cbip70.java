package lab.paybybitcoinj;

import java.io.File;

import org.bitcoinj.core.Address;
import org.bitcoinj.core.NetworkParameters;
import org.bitcoinj.kits.WalletAppKit;
import org.bitcoinj.params.TestNet3Params;
import org.bitcoinj.protocols.payments.PaymentProtocol;
import org.bitcoinj.protocols.payments.PaymentSession;
import org.bitcoinj.uri.BitcoinURI;
import org.bitcoinj.utils.BriefLogFormatter;
import org.bitcoinj.wallet.SendRequest;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.google.common.collect.ImmutableList;
import com.google.common.util.concurrent.ListenableFuture;

public class Cbip70 {
	final static NetworkParameters params = TestNet3Params.get();
	final static Logger log = LoggerFactory.getLogger(Cbip70.class);

	public static void main(String[] args) {
		BriefLogFormatter.init();
		WalletAppKit kit = new WalletAppKit(params, new File("."), "walletappkit");

		kit.startAsync();
		kit.awaitRunning();

		Address customerAddress = kit.wallet().currentReceiveAddress();
		System.out.println("Customer's address : " + customerAddress);
		System.out.println("Customer's Balance : " + kit.wallet().getBalance());
		// mhc5YipxN6GhRRXtgakRBjrNUCbz6ypg66
		// String url =
		// "bitcoin:2N7BPybxuJ5XzBpjnMtaB6S2HvdATz7da9j?r=http://192.168.0.107:3000/request?amount=880";
		String url = "bitcoin:2N7BPybxuJ5XzBpjnMtaB6S2HvdATz7da9j?amount=0.00000880&message=payment%20request&r=http://192.168.0.107:3000/request?amount=880";
		if (Float.parseFloat(String.valueOf(kit.wallet().getBalance())) == 0.0) {
			System.out.println(
					"Please send some testnet Bitcoins to your address " + kit.wallet().currentReceiveAddress());
		} else {
			sendPaymentRequest(url, kit);
		}
	}

	private static void sendPaymentRequest(String location, WalletAppKit k) {
		try {
			if (location.startsWith("bitcoin")) {
				BitcoinURI paymentRequestURI = new BitcoinURI(location);
				ListenableFuture<PaymentSession> future = PaymentSession.createFromBitcoinUri(paymentRequestURI, true);
				PaymentSession session = future.get();
				if (session.isExpired()) {
					log.warn("request expired!");
				} else { // payment requests persist only for a certain duration.
					send(session, k);
					System.exit(1);
				}
			} else {
				log.info("Try to open the payment request as a file");
			}
		} catch (Exception e) {
			System.err.println(e.getMessage());
		}
	}

	private static void send(PaymentSession session, WalletAppKit k) {
		try {
			log.info("Payment Request");
			log.info("Amount to Pay: " + session.getValue().toFriendlyString());
			log.info("Date: " + session.getDate()); // Probably indicates what your are paying for.
			log.info("Message from merchant : " + session.getMemo());
			PaymentProtocol.PkiVerificationData identity = session.verifyPki();
			if (identity != null) { // Merchant identity from the certificate
				log.info("Payment requester: " + identity.displayName); // The i ssuing Certificate Authority
				log.info("Certificate authority: " + identity.rootAuthorityName);
			}

			final SendRequest request = session.getSendRequest();
			k.wallet().completeTx(request);
			String customerMemo = "Nice Website";
			Address refundAddress = new Address(params, "mii3cKuKybVRVXBQ36iddd2qxtdz7ZQNAR");
			ListenableFuture<PaymentProtocol.Ack> future = session.sendPayment(ImmutableList.of(request.tx),
					refundAddress, customerMemo);
			if (future != null) {
				PaymentProtocol.Ack ack = future.get();
				k.wallet().commitTx(request.tx);
				System.out.println("Memo from merchant :"+ack.getMemo());
				log.info("Stopping The node...");
				k.stopAsync();
				k.awaitTerminated();
			}

		} catch (Exception e) {
			System.err.println("Failed to send payment " + e.getMessage());
			// System.exit(1);
		}
	}
}
