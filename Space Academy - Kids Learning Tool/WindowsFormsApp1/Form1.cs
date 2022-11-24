using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        //browser button 

        private void browserButton_Click(object sender, EventArgs e)
        {
            Browser newForm = new Browser();
            newForm.Show();
        }


        //writing button
        private void button2_Click(object sender, EventArgs e)
        {
           Writing_Tool newForm = new Writing_Tool();
            newForm.Show();
        }

        //calculator button
        private void button1_Click(object sender, EventArgs e)
        {
                Calculator newForm = new Calculator();
            newForm.Show();

        }

        //mouse over event

        Image calcBkg = WindowsFormsApp1.Properties.Resources.calc2_fw;

        private void calculatorButton_MouseEnter(object sender, EventArgs e)
        {
            calculatorButton.BackgroundImage = calcBkg;
            //calculatorButton.BackgroundImage = ((System.Drawing.Image)(Properties.Resources.calc2_fw));
        }

        private void calculatorButton_MouseLeave(object sender, EventArgs e)
        {
            calculatorButton.BackgroundImage = null;
        
        }
           



    }
}
