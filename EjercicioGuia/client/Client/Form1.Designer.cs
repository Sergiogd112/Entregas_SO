namespace Client
{
    partial class Form1
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
            label1 = new Label();
            Nombre = new TextBox();
            bonito = new RadioButton();
            Longitud = new RadioButton();
            Enviar = new Button();
            Connect = new Button();
            Disconnect = new Button();
            alto = new RadioButton();
            Altura = new TextBox();
            SuspendLayout();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.ForeColor = SystemColors.ControlLightLight;
            label1.Location = new Point(100, 92);
            label1.Name = "label1";
            label1.Size = new Size(64, 20);
            label1.TabIndex = 0;
            label1.Text = "Nombre";
            // 
            // Nombre
            // 
            Nombre.Location = new Point(196, 84);
            Nombre.Name = "Nombre";
            Nombre.Size = new Size(356, 27);
            Nombre.TabIndex = 1;
            // 
            // bonito
            // 
            bonito.AutoSize = true;
            bonito.ForeColor = SystemColors.ControlLightLight;
            bonito.Location = new Point(196, 140);
            bonito.Name = "bonito";
            bonito.Size = new Size(133, 24);
            bonito.TabIndex = 2;
            bonito.TabStop = true;
            bonito.Text = "Nombre bonito";
            bonito.UseVisualStyleBackColor = true;
            // 
            // Longitud
            // 
            Longitud.AutoSize = true;
            Longitud.ForeColor = SystemColors.ControlLightLight;
            Longitud.Location = new Point(196, 181);
            Longitud.Name = "Longitud";
            Longitud.Size = new Size(89, 24);
            Longitud.TabIndex = 3;
            Longitud.TabStop = true;
            Longitud.Text = "Longitud";
            Longitud.UseVisualStyleBackColor = true;
            // 
            // Enviar
            // 
            Enviar.Location = new Point(216, 269);
            Enviar.Name = "Enviar";
            Enviar.Size = new Size(325, 82);
            Enviar.TabIndex = 4;
            Enviar.Text = "Enviar";
            Enviar.UseVisualStyleBackColor = true;
            Enviar.Click += Enviar_Click;
            // 
            // Connect
            // 
            Connect.Location = new Point(590, 49);
            Connect.Name = "Connect";
            Connect.Size = new Size(185, 52);
            Connect.TabIndex = 5;
            Connect.Text = "Connectar";
            Connect.UseVisualStyleBackColor = true;
            Connect.Click += Connect_Click;
            // 
            // Disconnect
            // 
            Disconnect.Location = new Point(587, 141);
            Disconnect.Name = "Disconnect";
            Disconnect.Size = new Size(190, 63);
            Disconnect.TabIndex = 6;
            Disconnect.Text = "Desconectar";
            Disconnect.UseVisualStyleBackColor = true;
            Disconnect.Click += Disconnect_Click;
            // 
            // alto
            // 
            alto.AutoSize = true;
            alto.ForeColor = SystemColors.ControlLightLight;
            alto.Location = new Point(196, 225);
            alto.Name = "alto";
            alto.Size = new Size(141, 24);
            alto.TabIndex = 7;
            alto.TabStop = true;
            alto.Text = "Dime si soy alt@";
            alto.UseVisualStyleBackColor = true;
            // 
            // Altura
            // 
            Altura.Location = new Point(363, 225);
            Altura.Name = "Altura";
            Altura.Size = new Size(178, 27);
            Altura.TabIndex = 8;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.DimGray;
            ClientSize = new Size(800, 450);
            Controls.Add(Altura);
            Controls.Add(alto);
            Controls.Add(Disconnect);
            Controls.Add(Connect);
            Controls.Add(Enviar);
            Controls.Add(Longitud);
            Controls.Add(bonito);
            Controls.Add(Nombre);
            Controls.Add(label1);
            Name = "Form1";
            Text = "Form1";
            Load += Form1_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label1;
        private TextBox Nombre;
        private RadioButton bonito;
        private RadioButton Longitud;
        private Button Enviar;
        private Button Connect;
        private Button Disconnect;
        private RadioButton alto;
        private TextBox Altura;
    }
}