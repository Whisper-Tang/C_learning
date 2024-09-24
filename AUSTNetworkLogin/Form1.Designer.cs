namespace AUSTNetworkLogin
{
    partial class AUSTLOGIN
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(AUSTLOGIN));
            lblUsername = new Label();
            txtUsername = new TextBox();
            lblPassword = new Label();
            lblLine = new Label();
            txtPassword = new TextBox();
            cmbLine = new ComboBox();
            btnLogin = new Button();
            chkAutoLogin = new CheckBox();
            SuspendLayout();
            // 
            // lblUsername
            // 
            lblUsername.AutoSize = true;
            lblUsername.BackColor = SystemColors.ButtonHighlight;
            lblUsername.Font = new Font("得意黑", 9F, FontStyle.Italic);
            lblUsername.Location = new Point(39, 32);
            lblUsername.Name = "lblUsername";
            lblUsername.RightToLeft = RightToLeft.No;
            lblUsername.Size = new Size(31, 15);
            lblUsername.TabIndex = 0;
            lblUsername.Text = "账  号";
            lblUsername.Click += label1_Click;
            // 
            // txtUsername
            // 
            txtUsername.BackColor = SystemColors.ButtonHighlight;
            txtUsername.Font = new Font("得意黑", 9F, FontStyle.Italic);
            txtUsername.Location = new Point(99, 28);
            txtUsername.Margin = new Padding(3, 4, 3, 4);
            txtUsername.Name = "txtUsername";
            txtUsername.RightToLeft = RightToLeft.No;
            txtUsername.Size = new Size(164, 22);
            txtUsername.TabIndex = 1;
            // 
            // lblPassword
            // 
            lblPassword.AutoSize = true;
            lblPassword.BackColor = SystemColors.ButtonHighlight;
            lblPassword.Font = new Font("得意黑", 9F, FontStyle.Italic);
            lblPassword.Location = new Point(41, 73);
            lblPassword.Name = "lblPassword";
            lblPassword.RightToLeft = RightToLeft.No;
            lblPassword.Size = new Size(31, 15);
            lblPassword.TabIndex = 2;
            lblPassword.Text = "密  码";
            lblPassword.Click += label2_Click;
            // 
            // lblLine
            // 
            lblLine.AutoSize = true;
            lblLine.BackColor = SystemColors.ButtonHighlight;
            lblLine.Font = new Font("得意黑", 9F, FontStyle.Italic);
            lblLine.Location = new Point(41, 111);
            lblLine.Name = "lblLine";
            lblLine.RightToLeft = RightToLeft.No;
            lblLine.Size = new Size(37, 15);
            lblLine.TabIndex = 3;
            lblLine.Text = "运营商";
            lblLine.Click += label3_Click;
            // 
            // txtPassword
            // 
            txtPassword.BackColor = SystemColors.ButtonHighlight;
            txtPassword.Font = new Font("得意黑", 9F, FontStyle.Italic);
            txtPassword.Location = new Point(99, 69);
            txtPassword.Margin = new Padding(3, 4, 3, 4);
            txtPassword.Name = "txtPassword";
            txtPassword.RightToLeft = RightToLeft.No;
            txtPassword.Size = new Size(164, 22);
            txtPassword.TabIndex = 4;
            txtPassword.UseSystemPasswordChar = true;
            // 
            // cmbLine
            // 
            cmbLine.BackColor = SystemColors.ButtonHighlight;
            cmbLine.Font = new Font("得意黑", 9F, FontStyle.Italic);
            cmbLine.FormattingEnabled = true;
            cmbLine.Items.AddRange(new object[] { "移不动", "联不通", "电不信", "教职工" });
            cmbLine.Location = new Point(99, 107);
            cmbLine.Margin = new Padding(3, 4, 3, 4);
            cmbLine.Name = "cmbLine";
            cmbLine.RightToLeft = RightToLeft.No;
            cmbLine.Size = new Size(164, 23);
            cmbLine.TabIndex = 5;
            cmbLine.SelectedIndexChanged += button1_Click;
            // 
            // btnLogin
            // 
            btnLogin.BackColor = SystemColors.ButtonHighlight;
            btnLogin.Font = new Font("得意黑", 9F, FontStyle.Italic);
            btnLogin.Location = new Point(161, 158);
            btnLogin.Margin = new Padding(3, 4, 3, 4);
            btnLogin.Name = "btnLogin";
            btnLogin.RightToLeft = RightToLeft.No;
            btnLogin.Size = new Size(102, 41);
            btnLogin.TabIndex = 6;
            btnLogin.Text = "确认登陆";
            btnLogin.UseVisualStyleBackColor = false;
            btnLogin.Click += button1_Click;
            // 
            // chkAutoLogin
            // 
            chkAutoLogin.AutoSize = true;
            chkAutoLogin.BackColor = SystemColors.ButtonHighlight;
            chkAutoLogin.Font = new Font("得意黑", 9F, FontStyle.Italic);
            chkAutoLogin.Location = new Point(38, 170);
            chkAutoLogin.Margin = new Padding(3, 4, 3, 4);
            chkAutoLogin.Name = "chkAutoLogin";
            chkAutoLogin.RightToLeft = RightToLeft.No;
            chkAutoLogin.Size = new Size(86, 19);
            chkAutoLogin.TabIndex = 7;
            chkAutoLogin.Text = "开机自动登录";
            chkAutoLogin.UseVisualStyleBackColor = false;
            chkAutoLogin.CheckedChanged += checkBox1_CheckedChanged;
            // 
            // AUSTLOGIN
            // 
            AutoScaleDimensions = new SizeF(8F, 22F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = SystemColors.ButtonHighlight;
            BackgroundImage = Properties.Resources.backgrand;
            BackgroundImageLayout = ImageLayout.Center;
            ClientSize = new Size(291, 204);
            Controls.Add(chkAutoLogin);
            Controls.Add(btnLogin);
            Controls.Add(cmbLine);
            Controls.Add(txtPassword);
            Controls.Add(lblLine);
            Controls.Add(lblPassword);
            Controls.Add(txtUsername);
            Controls.Add(lblUsername);
            Font = new Font("得意黑", 14.25F, FontStyle.Italic, GraphicsUnit.Point, 134);
            Icon = (Icon)resources.GetObject("$this.Icon");
            Margin = new Padding(3, 4, 3, 4);
            Name = "AUSTLOGIN";
            Text = "AUST校园网登录程序";
            Load += Form1_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label lblUsername;
        private TextBox txtUsername;
        private Label lblPassword;
        private Label lblLine;
        private TextBox txtPassword;
        private ComboBox cmbLine;
        private Button btnLogin;
        private CheckBox chkAutoLogin;
    }
}
