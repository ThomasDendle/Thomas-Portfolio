namespace WindowsFormsApp1
{
    partial class Form1
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.flowLayoutPanel1 = new System.Windows.Forms.FlowLayoutPanel();
            this.calculatorButton = new System.Windows.Forms.Button();
            this.labelCalc = new System.Windows.Forms.Label();
            this.flowLayoutPanel2 = new System.Windows.Forms.FlowLayoutPanel();
            this.writingButton = new System.Windows.Forms.Button();
            this.labelWriting = new System.Windows.Forms.Label();
            this.flowLayoutPanel3 = new System.Windows.Forms.FlowLayoutPanel();
            this.browserButton = new System.Windows.Forms.Button();
            this.labelBrowser = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.tableLayoutPanel1.SuspendLayout();
            this.flowLayoutPanel1.SuspendLayout();
            this.flowLayoutPanel2.SuspendLayout();
            this.flowLayoutPanel3.SuspendLayout();
            this.SuspendLayout();
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.BackColor = System.Drawing.Color.Transparent;
            this.tableLayoutPanel1.ColumnCount = 5;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 11F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 26F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 26F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 26F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 11F));
            this.tableLayoutPanel1.Controls.Add(this.flowLayoutPanel1, 1, 1);
            this.tableLayoutPanel1.Controls.Add(this.flowLayoutPanel2, 3, 1);
            this.tableLayoutPanel1.Controls.Add(this.flowLayoutPanel3, 2, 3);
            this.tableLayoutPanel1.Controls.Add(this.label5, 1, 0);
            this.tableLayoutPanel1.Controls.Add(this.label1, 2, 1);
            this.tableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel1.Location = new System.Drawing.Point(0, 0);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 4;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 22.22222F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 43.90244F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 4.607046F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 29.20962F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(739, 738);
            this.tableLayoutPanel1.TabIndex = 0;
            // 
            // flowLayoutPanel1
            // 
            this.flowLayoutPanel1.Controls.Add(this.calculatorButton);
            this.flowLayoutPanel1.Controls.Add(this.labelCalc);
            this.flowLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.flowLayoutPanel1.FlowDirection = System.Windows.Forms.FlowDirection.RightToLeft;
            this.flowLayoutPanel1.Location = new System.Drawing.Point(84, 167);
            this.flowLayoutPanel1.Name = "flowLayoutPanel1";
            this.flowLayoutPanel1.Size = new System.Drawing.Size(186, 318);
            this.flowLayoutPanel1.TabIndex = 5;
            // 
            // calculatorButton
            // 
            this.calculatorButton.AutoSize = true;
            this.calculatorButton.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("calculatorButton.BackgroundImage")));
            this.calculatorButton.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.calculatorButton.Dock = System.Windows.Forms.DockStyle.Fill;
            this.calculatorButton.Location = new System.Drawing.Point(36, 3);
            this.calculatorButton.Name = "calculatorButton";
            this.calculatorButton.Size = new System.Drawing.Size(147, 129);
            this.calculatorButton.TabIndex = 0;
            this.calculatorButton.UseVisualStyleBackColor = true;
            this.calculatorButton.Click += new System.EventHandler(this.button1_Click);
            // 
            // labelCalc
            // 
            this.labelCalc.AutoSize = true;
            this.labelCalc.Dock = System.Windows.Forms.DockStyle.Fill;
            this.labelCalc.Font = new System.Drawing.Font("MS Reference Sans Serif", 13.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelCalc.ForeColor = System.Drawing.SystemColors.Info;
            this.labelCalc.Location = new System.Drawing.Point(22, 135);
            this.labelCalc.Name = "labelCalc";
            this.labelCalc.Size = new System.Drawing.Size(161, 58);
            this.labelCalc.TabIndex = 3;
            this.labelCalc.Text = "Use the Calculator! ";
            this.labelCalc.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // flowLayoutPanel2
            // 
            this.flowLayoutPanel2.Controls.Add(this.writingButton);
            this.flowLayoutPanel2.Controls.Add(this.labelWriting);
            this.flowLayoutPanel2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.flowLayoutPanel2.Location = new System.Drawing.Point(468, 167);
            this.flowLayoutPanel2.Name = "flowLayoutPanel2";
            this.flowLayoutPanel2.Size = new System.Drawing.Size(186, 318);
            this.flowLayoutPanel2.TabIndex = 6;
            // 
            // writingButton
            // 
            this.writingButton.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.writingButton.AutoSize = true;
            this.writingButton.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.writingButton.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("writingButton.BackgroundImage")));
            this.writingButton.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.writingButton.Location = new System.Drawing.Point(3, 3);
            this.writingButton.Name = "writingButton";
            this.writingButton.Size = new System.Drawing.Size(147, 129);
            this.writingButton.TabIndex = 1;
            this.writingButton.UseVisualStyleBackColor = false;
            this.writingButton.Click += new System.EventHandler(this.button2_Click);
            // 
            // labelWriting
            // 
            this.labelWriting.AutoSize = true;
            this.labelWriting.Font = new System.Drawing.Font("MS Reference Sans Serif", 13.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelWriting.ForeColor = System.Drawing.SystemColors.Info;
            this.labelWriting.Location = new System.Drawing.Point(3, 135);
            this.labelWriting.Name = "labelWriting";
            this.labelWriting.Size = new System.Drawing.Size(136, 58);
            this.labelWriting.TabIndex = 2;
            this.labelWriting.Text = "Do some writing!";
            // 
            // flowLayoutPanel3
            // 
            this.flowLayoutPanel3.Controls.Add(this.browserButton);
            this.flowLayoutPanel3.Controls.Add(this.labelBrowser);
            this.flowLayoutPanel3.Dock = System.Windows.Forms.DockStyle.Fill;
            this.flowLayoutPanel3.Location = new System.Drawing.Point(276, 525);
            this.flowLayoutPanel3.Name = "flowLayoutPanel3";
            this.flowLayoutPanel3.Size = new System.Drawing.Size(186, 210);
            this.flowLayoutPanel3.TabIndex = 11;
            // 
            // browserButton
            // 
            this.browserButton.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("browserButton.BackgroundImage")));
            this.browserButton.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.browserButton.Dock = System.Windows.Forms.DockStyle.Top;
            this.browserButton.Location = new System.Drawing.Point(3, 3);
            this.browserButton.Name = "browserButton";
            this.browserButton.Size = new System.Drawing.Size(190, 135);
            this.browserButton.TabIndex = 2;
            this.browserButton.Click += new System.EventHandler(this.browserButton_Click);
            // 
            // labelBrowser
            // 
            this.labelBrowser.Font = new System.Drawing.Font("MS Reference Sans Serif", 13.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelBrowser.ForeColor = System.Drawing.SystemColors.Info;
            this.labelBrowser.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.labelBrowser.Location = new System.Drawing.Point(3, 141);
            this.labelBrowser.Name = "labelBrowser";
            this.labelBrowser.Size = new System.Drawing.Size(190, 58);
            this.labelBrowser.TabIndex = 10;
            this.labelBrowser.Text = "Browse the web!";
            this.labelBrowser.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // label5
            // 
            this.label5.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.label5.AutoSize = true;
            this.tableLayoutPanel1.SetColumnSpan(this.label5, 3);
            this.label5.Font = new System.Drawing.Font("Ravie", 19.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.ForeColor = System.Drawing.Color.White;
            this.label5.Location = new System.Drawing.Point(153, 38);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(431, 88);
            this.label5.TabIndex = 12;
            this.label5.Text = "Welcome to Space Academy!";
            this.label5.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            
            // 
            // label1
            // 
            this.label1.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Gill Sans Ultra Bold", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.label1.Location = new System.Drawing.Point(276, 164);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(185, 300);
            this.label1.TabIndex = 13;
            this.label1.Text = "Welcome, Recruit, to Space Academy! Here you can practise the skills you need to " +
    "be an astronaut! Use your mouse to click on any of the 3 boxes below.";
            this.label1.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.ClientSize = new System.Drawing.Size(739, 738);
            this.Controls.Add(this.tableLayoutPanel1);
            this.DoubleBuffered = true;
            this.Name = "Form1";
            this.Text = "Form1";
            
            this.tableLayoutPanel1.ResumeLayout(false);
            this.tableLayoutPanel1.PerformLayout();
            this.flowLayoutPanel1.ResumeLayout(false);
            this.flowLayoutPanel1.PerformLayout();
            this.flowLayoutPanel2.ResumeLayout(false);
            this.flowLayoutPanel2.PerformLayout();
            this.flowLayoutPanel3.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.Button writingButton;
        public System.Windows.Forms.Button calculatorButton;
        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel1;
        private System.Windows.Forms.Label labelCalc;
        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel2;
        private System.Windows.Forms.Label labelWriting;
        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel3;
        private System.Windows.Forms.Button browserButton;
        private System.Windows.Forms.Label labelBrowser;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label1;
    }
}

