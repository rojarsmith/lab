using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PokerSize
{
    public class ConditionStraightFlush : Condition
    {
        /// <summary>
        /// Check "A-K-Q-J-10"
        /// </summary>
        /// <param name="player"></param>
        /// <returns></returns>
        public override int getScore(List<Card> player)
        {
            int score = 0;
            int condition = 0;            

            // Check point.            
            if (
                (player[0]._CardPoint - player[1]._CardPoint == 1) &&
                (player[1]._CardPoint - player[2]._CardPoint == 1) &&
                (player[2]._CardPoint - player[3]._CardPoint == 1) &&
                (player[3]._CardPoint - player[4]._CardPoint == 1)
                )
            {
                condition += 1;
            }

            if (1 == condition)
            {
                score = 9000;
            }

            return score;
        }
    }
}
