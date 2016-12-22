using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PokerSize
{
    public class ScoreManager
    {
        List<Condition> _Conditions;
        List<Card> _player1;
        List<Card> _player2;
        int _score1;
        int _score2;
        public String _winner;

        public ScoreManager(List<Card> player1, List<Card> player2)
        { 
            // Initial            
            _Conditions = new List<Condition>()
            {
                // TODO : Add more condition.
                new ConditionSuperStraightFlush(),
                new ConditionStraightFlush()
            };

            // Sort : big to small
            _player1 = player1.OrderByDescending(o => o._CardPoint).ToList();
            _player2 = player2.OrderByDescending(o => o._CardPoint).ToList();

            // Get highest score
            _score1 = GetHighestScore(_player1);
            _score2 = GetHighestScore(_player2);

            // Who win
            if(_score1 > _score2)
            {
                _winner = "Player 1";
            }else if(_score1 < _score2)
            {
                _winner = "Player 2";
            }
            else
            {
                _winner = "None";
            }
        }

        public int GetHighestScore(List<Card> player)
        {
            int score = 0;

            foreach (var c in _Conditions)
            {                
               score = c.getScore(player);
                if (0 < score)
                {
                    break;
                }
            }

            return score;
        }
    }
}
