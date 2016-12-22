using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PokerSize
{
    /// <summary>
    /// S : spade
    /// H : heart
    /// C : club
    /// D : diamond
    /// Point : 1~13, J=11, Q=12, K=13, A=14
    /// </summary>
    class Program
    {
        static ScoreManager _ScoreManager;

        static void Main(string[] args)
        {
            List<Card> player1 = new List<Card>() {
                new Card(CardTyep.Diamond, "J"),
                new Card(CardTyep.Heart, "A"),
                new Card(CardTyep.Heart, "K"),
                new Card(CardTyep.Heart, "Q"),
                new Card(CardTyep.Heart, "10")
            };

            List<Card> player2 = new List<Card>() {
                new Card(CardTyep.Diamond, "A"),
                new Card(CardTyep.Heart, "K"),
                new Card(CardTyep.Heart, "Q"),
                new Card(CardTyep.Heart, "J"),
                new Card(CardTyep.Heart, "10")
            };

            _ScoreManager = new PokerSize.ScoreManager(player1, player2);

            Console.WriteLine("Winner is " + _ScoreManager._winner);
        }
    }
}
