using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PokerSize
{
    abstract public class Condition
    {
        public abstract int getScore(List<Card> player);
    }
}
