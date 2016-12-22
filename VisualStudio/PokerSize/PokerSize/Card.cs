using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PokerSize
{
    public enum CardTyep { Spade, Heart, Club, Diamond };    

    public class Card
    {
        public CardTyep _CardType;
        public int _CardPoint;        

        public string CardPoint
        {
            get
            {
                return toCardViewPoint(_CardPoint);
            }
            set
            {                
                _CardPoint = toCardPoint(value);
            }
        }

        public Card(CardTyep cardtype, string cardpoint)
        {
            _CardType = cardtype;
            CardPoint = cardpoint;
        }

        int toCardPoint(string value)
        {
            string valueU = value.ToUpper();
            if("J" == valueU)
            {
                return 11;
            }else if("Q" == valueU)
            {
                return 12;
            }
            else if ("K" == valueU)
            {
                return 13;
            }
            else if ("A" == valueU)
            {
                return 14;
            }else
            {
                int tmp = 0;
                int.TryParse(value, out tmp);
                return tmp;
            }
        }

        string toCardViewPoint(int value)
        {            
            if (11 == value)
            {
                return "J";
            }
            else if (12 == value)
            {
                return "K";
            }
            else if (13 == value)
            {
                return "Q";
            }
            else if (14 == value)
            {
                return "A";
            }
            else
            {
                return value.ToString();
            }
        }
    }
}