using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Net;
using System.Net.Sockets;

namespace Client
{
    public partial class Form1 : Form
    {
        Socket server;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }



        private void Enviar_Click(object sender, EventArgs e)
        {
            
            this.BackColor = Color.Green;
            if (Longitud.Checked)
            {
                string message = "1/" + Nombre.Text;
                byte[] msg = Encoding.ASCII.GetBytes(message);
                server.Send(msg);
                byte[] msg2 = new byte[80];
                server.Receive(msg2);
                message = Encoding.ASCII.GetString(msg2).Split('\0')[0];
                MessageBox.Show("La longitud del nombre es: " + message);
            }
            else if (bonito.Checked)
            {
                string message = "2/" + Nombre.Text;
                byte[] msg = Encoding.ASCII.GetBytes(message);
                server.Send(msg);
                byte[] msg2 = new byte[80];
                server.Receive(msg2);
                message = Encoding.ASCII.GetString(msg2).Split('\0')[0];
                MessageBox.Show("¿Es bonito tu nombre? " + message);
            }
            else
            {
                string message = "3/" + Nombre.Text + "/" + Altura.Text;
                MessageBox.Show(message);
                byte[] msg = Encoding.ASCII.GetBytes(message);
                server.Send(msg);
                byte[] msg2 = new byte[80];
                server.Receive(msg2);
                message = Encoding.ASCII.GetString(msg2).Split('\0')[0];
                MessageBox.Show(message);
            }


        }

        private void Connect_Click(object sender, EventArgs e)
        {
            IPAddress address = IPAddress.Parse("172.23.134.41");
            IPEndPoint ipep = new IPEndPoint(address, 9050);


            server = new Socket(AddressFamily.InterNetwork,
                SocketType.Stream,
                ProtocolType.Tcp);
            try
            {
                server.Connect(ipep);
                this.BackColor = Color.Green;
                MessageBox.Show("Conectado");
            }
            catch (SocketException ex)
            {
                MessageBox.Show("No me he podido conectar");
                return;
            }
        }

        private void Disconnect_Click(object sender, EventArgs e)
        {
            string message = "0/";
            byte[] msg = Encoding.ASCII.GetBytes(message);
            server.Send(msg);
            this.BackColor = Color.DimGray;
            server.Shutdown(SocketShutdown.Both);
            server.Close();
            MessageBox.Show("Desconectado");

        }
    }
}