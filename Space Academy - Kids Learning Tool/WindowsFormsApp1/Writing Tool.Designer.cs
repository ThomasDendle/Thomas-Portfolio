namespace WindowsFormsApp1
{
    partial class Writing_Tool
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Writing_Tool));
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.fontButton = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.colourButton = new System.Windows.Forms.Button();
            this.saveButton = new System.Windows.Forms.Button();
            this.openButton = new System.Windows.Forms.Button();
            this.colorDialog1 = new System.Windows.Forms.ColorDialog();
            this.fontDialog1 = new System.Windows.Forms.FontDialog();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.saveFileDialog1 = new System.Windows.Forms.SaveFileDialog();
            this.label3 = new System.Windows.Forms.Label();
            this.helpButton = new System.Windows.Forms.Button();
            this.toolTip1 = new System.Windows.Forms.ToolTip(this.components);
            this.tableLayoutPanel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.tableLayoutPanel1.BackColor = System.Drawing.Color.PaleTurquoise;
            this.tableLayoutPanel1.ColumnCount = 4;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 20F));
            this.tableLayoutPanel1.Controls.Add(this.fontButton, 0, 1);
            this.tableLayoutPanel1.Controls.Add(this.textBox1, 0, 0);
            this.tableLayoutPanel1.Controls.Add(this.colourButton, 1, 1);
            this.tableLayoutPanel1.Controls.Add(this.saveButton, 2, 1);
            this.tableLayoutPanel1.Controls.Add(this.openButton, 3, 1);
            this.tableLayoutPanel1.Location = new System.Drawing.Point(62, 120);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 2;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 84.41558F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 15.58442F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 20F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(600, 459);
            this.tableLayoutPanel1.TabIndex = 0;
            // 
            // fontButton
            // 
            this.fontButton.BackColor = System.Drawing.SystemColors.Highlight;
            this.fontButton.Dock = System.Windows.Forms.DockStyle.Fill;
            this.fontButton.Location = new System.Drawing.Point(3, 390);
            this.fontButton.Name = "fontButton";
            this.fontButton.Size = new System.Drawing.Size(144, 66);
            this.fontButton.TabIndex = 1;
            this.fontButton.Text = "Change Font";
            this.fontButton.UseVisualStyleBackColor = false;
            this.fontButton.Click += new System.EventHandler(this.fontButton_Click);
            // 
            // textBox1
            // 
            this.textBox1.BackColor = System.Drawing.Color.PaleTurquoise;
            this.tableLayoutPanel1.SetColumnSpan(this.textBox1, 4);
            this.textBox1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.textBox1.Location = new System.Drawing.Point(3, 3);
            this.textBox1.Multiline = true;
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(594, 381);
            this.textBox1.TabIndex = 6;
            this.textBox1.Text = "Try writing about the Moon!";
            // 
            // colourButton
            // 
            this.colourButton.BackColor = System.Drawing.SystemColors.Highlight;
            this.colourButton.Dock = System.Windows.Forms.DockStyle.Fill;
            this.colourButton.Location = new System.Drawing.Point(153, 390);
            this.colourButton.Name = "colourButton";
            this.colourButton.Size = new System.Drawing.Size(144, 66);
            this.colourButton.TabIndex = 3;
            this.colourButton.Text = "Change Colour";
            this.colourButton.UseVisualStyleBackColor = false;
            this.colourButton.Click += new System.EventHandler(this.colourButton_Click);
            // 
            // saveButton
            // 
            this.saveButton.BackColor = System.Drawing.SystemColors.Highlight;
            this.saveButton.Dock = System.Windows.Forms.DockStyle.Fill;
            this.saveButton.Location = new System.Drawing.Point(303, 390);
            this.saveButton.Name = "saveButton";
            this.saveButton.Size = new System.Drawing.Size(144, 66);
            this.saveButton.TabIndex = 4;
            this.saveButton.Text = "Save";
            this.saveButton.UseVisualStyleBackColor = false;
            this.saveButton.Click += new System.EventHandler(this.saveButton_Click);
            // 
            // openButton
            // 
            this.openButton.BackColor = System.Drawing.SystemColors.Highlight;
            this.openButton.Dock = System.Windows.Forms.DockStyle.Fill;
            this.openButton.Location = new System.Drawing.Point(453, 390);
            this.openButton.Name = "openButton";
            this.openButton.Size = new System.Drawing.Size(144, 66);
            this.openButton.TabIndex = 5;
            this.openButton.Text = "Open";
            this.openButton.UseVisualStyleBackColor = false;
            this.openButton.Click += new System.EventHandler(this.openButton_Click);
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            this.openFileDialog1.Filter = "txt Files (*.txt)|*.txt";
            this.openFileDialog1.Title = "Select a .txt file to open!";
           
            // 
            // saveFileDialog1
            // 
            this.saveFileDialog1.Filter = "txt Files (*.txt)|*.txt";
            this.saveFileDialog1.Title = "Save your work!";
            this.saveFileDialog1.FileOk += new System.ComponentModel.CancelEventHandler(this.saveFileDialog1_FileOk);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.BackColor = System.Drawing.Color.Transparent;
            this.label3.Font = new System.Drawing.Font("Cooper Black", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.ForeColor = System.Drawing.Color.Transparent;
            this.label3.Location = new System.Drawing.Point(126, 36);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(473, 70);
            this.label3.TabIndex = 26;
            this.label3.Text = "Practise writing! Have fun\r\n changing the colour and font!";
            this.label3.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
      
            // 
            // helpButton
            // 
            this.helpButton.BackColor = System.Drawing.SystemColors.ButtonShadow;
            this.helpButton.Location = new System.Drawing.Point(295, 611);
            this.helpButton.Name = "helpButton";
            this.helpButton.Size = new System.Drawing.Size(134, 33);
            this.helpButton.TabIndex = 27;
            this.helpButton.Text = "Hover for Help!";
            this.toolTip1.SetToolTip(this.helpButton, resources.GetString("helpButton.ToolTip"));
            this.helpButton.UseVisualStyleBackColor = false;
            // 
            // Writing_Tool
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.ClientSize = new System.Drawing.Size(739, 738);
            this.Controls.Add(this.helpButton);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.tableLayoutPanel1);
            this.DoubleBuffered = true;
            this.Name = "Writing_Tool";
            this.Text = "Writing_Tool";
            
            this.tableLayoutPanel1.ResumeLayout(false);
            this.tableLayoutPanel1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.Button fontButton;
        private System.Windows.Forms.Button colourButton;
        private System.Windows.Forms.Button saveButton;
        private System.Windows.Forms.ColorDialog colorDialog1;
        private System.Windows.Forms.FontDialog fontDialog1;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.SaveFileDialog saveFileDialog1;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Button openButton;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button helpButton;
        private System.Windows.Forms.ToolTip toolTip1;
    }
}