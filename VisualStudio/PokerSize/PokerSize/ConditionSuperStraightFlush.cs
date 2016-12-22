using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PokerSize
{
    public class ConditionSuperStraightFlush : Condition
    {
        /// <summary>
        /// Check same color + "A-K-Q-J-10"
        /// </summary>
        /// <param name="player"></param>
        /// <returns></returns>
        public override int getScore(List<Card> player)
        {
            int score = 0;
            int condition = 0;

            // Check color.
            int count1 = player.Count(o => o._CardType == player[0]._CardType);

            if (5 == count1)
            {
                condition += 1;
            }

            // Check point.            
            if (
                (player[0]._CardPoint == 14) &&
                (player[0]._CardPoint - player[1]._CardPoint == 1) &&
                (player[1]._CardPoint - player[2]._CardPoint == 1) &&
                (player[2]._CardPoint - player[3]._CardPoint == 1) &&
                (player[3]._CardPoint - player[4]._CardPoint == 1)
                )
            {
                condition += 1;
            }

            if (2 == condition)
            {
                score = 10000;
            }

            return score;
        }
    }
}