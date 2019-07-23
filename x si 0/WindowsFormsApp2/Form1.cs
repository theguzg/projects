using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp2
{
    public partial class Form1 : Form
    {
        bool turn = true; // true = X, false = 0
        int turnCount = 0;


        public Form1()
        {
            InitializeComponent();
        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("By Gutza", "X si 0 About");
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void button_click(object sender, EventArgs e)
        {
            Button b = (Button)sender;

            if (turn)
                b.Text = "X";
            else
                b.Text = "0";

            turn = !turn;

            b.Enabled = false;

            turnCount++;
            checkForWinner();
        }

        private void checkForWinner()
        {
            bool winner = false;

            //horizontal checkuri ma
            if ((A1.Text == A2.Text) && (A2.Text == A3.Text) && (!A1.Enabled))
                winner = true;
            else if (B1.Text == B2.Text && B2.Text == B3.Text && (!B1.Enabled))
                winner = true;
            else if (C1.Text == C2.Text && C2.Text == C3.Text && (!C1.Enabled))
                winner = true;

            //diagonal checkuri ma
            if (A1.Text == B2.Text && B2.Text == C3.Text && (!A1.Enabled))
                winner = true;
            else if (A3.Text == B2.Text && B2.Text == C1.Text && (!A3.Enabled))
                winner = true;

            //vertical checkuri ma
            if (A1.Text == B1.Text && B1.Text == C1.Text && (!A1.Enabled))
                winner = true;
            else if (A2.Text == B2.Text && B2.Text == C2.Text && (!A2.Enabled))
                winner = true;
            else if (A3.Text == B3.Text && B3.Text == C3.Text && (!A3.Enabled))
                winner = true;




            if (winner)
            {
                disabledButton();

                String winner_name = "";

                if (turn)
                {
                    winner_name = "Player2";
                    o_win_count.Text = (Int32.Parse(o_win_count.Text) + 1).ToString();
                }
                else
                { 
                    winner_name = "Player1";
                    x_win_count.Text = (Int32.Parse(x_win_count.Text) + 1).ToString();
                }

                MessageBox.Show(winner_name + " wins!");

            }//end if
            else
            {
                if (turnCount == 9)
                {
                    draw_count.Text = (Int32.Parse(draw_count.Text) + 1).ToString();
                    MessageBox.Show("Draw!");
                }
            }



        } //end checkForWinner

        private void disabledButton()
        {
           
           foreach (Control c in Controls)
           {
                try
                {
                    Button b = (Button)c;
                    b.Enabled = false;
                }
                catch { }
           }//end foreach
           
        }

        private void newGameToolStripMenuItem_Click(object sender, EventArgs e)
        {
            turn = true;
            turnCount = 0;

            
                foreach (Control c in Controls)
                {
                try
                {
                    Button b = (Button)c;
                    b.Enabled = true;
                    b.Text = "";
                }//endtry
                catch { }
                }//end foreach
            
        }

        private void button_enter(object sender, EventArgs e)
        {
            Button b = (Button)sender;

            if (b.Enabled)
            {
                if (turn)
                    b.Text = "X";
                else
                    b.Text = "0";

            }//endif
        }

        private void button_leave(object sender, EventArgs e)
        {
            Button b = (Button)sender;

            if (b.Enabled)
            {
                b.Text = "";
            }//endif

        }

        private void resetScoreToolStripMenuItem_Click(object sender, EventArgs e)
        {
            draw_count.Text = "0";
            x_win_count.Text = "0";
            o_win_count.Text = "0";
        }
    }
}
