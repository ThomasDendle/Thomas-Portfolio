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
    public partial class Calculator : Form


    {
        
        //String operatorValue;
        int Answer = 0;
        bool inputbox1time = true;
        bool inputbox2time = false;
        int Input1 = 0;
        int Input2 = 0;
        //sets variables

        public Calculator()
        {
            InitializeComponent();

        }
        
        private void numberButton_Clicked(object sender, EventArgs e)
        {
            int numVal = 0;

            if (inputbox2time == true) //if time for input box 2, put number clicked there
            {
                if (inputBox2.Text == "0")
                { inputBox2.Clear(); }

                
                Button button = (Button)sender;
                inputBox2.Text = inputBox2.Text + button.Text;

                numVal = Int32.Parse(inputBox2.Text);

                Input2 = numVal;


            }

            if (inputbox1time == true) //if time for input box 1, put number clicked there
            {
                if (inputBox1.Text == "0")
                { inputBox1.Clear(); }

                

                Button button = (Button)sender;
                inputBox1.Text = inputBox1.Text + button.Text;

                numVal = Int32.Parse(inputBox1.Text);

                Input1 = numVal;
            }

            
        }

        private void equalsButton_Clicked(object sender, EventArgs e) //equals button
        {

            String operatorValue = operatorListBox.Items[operatorListBox.SelectedIndex].ToString();

         
            switch (operatorValue)
            {
                case "+":
                    Answer = Input1 + Input2;
                    break;
                case "*":
                    Answer = Input1 * Input2;
                    break;
                case "/":
                    Answer = Input1 / Input2;
                    break;
                case "-":
                    Answer = Input1 - Input2;
                    break;
                default:
                    break;

            }

            inputbox1time = true;
            inputbox2time = false;

            //result = Double.Parse(displayBox.Text);
            resultBox.Text = resultBox.Text + Answer;

        }

        //cancel

        private void cancelButton(object sender, EventArgs e)
        {
            Controls.Clear();
            InitializeComponent();
            inputbox1time = true;
            inputbox2time = false;
            /////////////////////////////////////this whole thing worked first time(once I chnaged approach) after like 3 hours, yay!

        }

        //sets which input box to use

        private void operatorListBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            inputbox1time = false;
            inputbox2time = true;
        }


    }
}
