using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace sistemcoordonate
{
    public partial class Form1 : Form
    {
        Graphics g; Pen p; Point cursor; Rectangle rect; SolidBrush whiteBrush; Point point1; Point point2;
        private bool button1IsClicked = false;

        int x1 = -1; int y1 = -1; int x2 = -1; int y2 = -1;


        public Form1()
        {
            InitializeComponent();

            p = new Pen(Color.Black, 2);
            rect = new Rectangle(300, 150, 300, 300);
            g = this.CreateGraphics();
            whiteBrush = new SolidBrush(Color.White);

            
            point1.X = x1;
            point1.Y = y1;

            point2.X = x2;
            point2.Y = y2;

        }

        private void button1_Click_1(object sender, EventArgs e)
        {


            button1IsClicked = true;

            if (!(String.IsNullOrWhiteSpace(xPoint1.Text)))
                x1 = Int32.Parse(xPoint1.Text);

            if (!(String.IsNullOrWhiteSpace(yPoint1.Text)))
                y1 = Int32.Parse(yPoint1.Text);

            if (!(String.IsNullOrWhiteSpace(xPoint2.Text)))
                x2 = Int32.Parse(xPoint2.Text);

            if (!(String.IsNullOrWhiteSpace(yPoint2.Text)))
                y2 = Int32.Parse(yPoint2.Text);

            if (x1 >= 0 && x1 <= 100 && y1 >= 0 && y1 <= 100 && x2 >= 0 && x2 <= 100 && y2 >= 0 && y2 <= 100 )
                g.DrawLine(p, x1 * 3 + 300, y1 + 450 - (y1 * 4), x2 * 3 + 300, y2 + 450 - (y2 * 4));

        }


        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            cursor = this.PointToClient(Cursor.Position);
            mouseStatus.Text = "X: " + ((cursor.X - 300) / 3) + "Y: " + ((cursor.Y - 450) / 3 * (-1));
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            g.FillRectangle(whiteBrush, rect);
            g.DrawRectangle(p, rect);

            if (button1IsClicked == true)
            {
                if (!(String.IsNullOrWhiteSpace(xPoint1.Text)))
                    x1 = Int32.Parse(xPoint1.Text);

                if (!(String.IsNullOrWhiteSpace(yPoint1.Text)))
                    y1 = Int32.Parse(yPoint1.Text);

                if (!(String.IsNullOrWhiteSpace(xPoint2.Text)))
                    x2 = Int32.Parse(xPoint2.Text);

                if (!(String.IsNullOrWhiteSpace(yPoint2.Text)))
                    y2 = Int32.Parse(yPoint2.Text);

                
                if (x1 >= 0 && x1 <= 100 && y1 >= 0 && y1 <= 100 && x2 >= 0 && x2 <= 100 && y2 >= 0 && y2 <= 100)
                    g.DrawLine(p, x1 * 3 + 300, y1 + 450 - (y1 * 4), x2 * 3 + 300, y2 + 450 - (y2 * 4));

                
            }

            

        }

        private void xPoint1_TextChanged(object sender, EventArgs e)
        {
            button1IsClicked = false;
        }

        private void yPoint1_TextChanged(object sender, EventArgs e)
        {
            button1IsClicked = false;
        }

        private void xPoint2_TextChanged(object sender, EventArgs e)
        {
            button1IsClicked = false;
        }

        private void yPoint2_TextChanged(object sender, EventArgs e)
        {
            button1IsClicked = false;
        }
    }

}