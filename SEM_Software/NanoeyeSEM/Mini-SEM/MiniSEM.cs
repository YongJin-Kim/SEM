using System;
using System.Collections.Generic;
using System.Windows.Forms;

using Microsoft.VisualBasic.ApplicationServices;

namespace SEC.Nanoeye.MiniSEM
{
    static class MiniSEM
    {
        /// <summary>
        /// 해당 응용 프로그램의 주 진입점입니다.
        /// </summary>
        [STAThread]
        public static void Main(string[] args)
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);

            SingleInstanceManager manager = new SingleInstanceManager();
            manager.Run(args);
        }
    }

    // Using VB bits to detect single instances and process accordingly:
    //  * OnStartup is fired when the first instance loads
    //  * OnStartupNextInstance is fired when the application is re-run again
    //    NOTE: it is redirected to this instance thanks to IsSingleInstance
    public class SingleInstanceManager : WindowsFormsApplicationBase
    {
        SingleInstanceApplication app;

        public SingleInstanceManager()
        {
            this.IsSingleInstance = false;
        }
        
        protected override bool OnStartup(Microsoft.VisualBasic.ApplicationServices.StartupEventArgs e)
        {
            // First time app is launched
            app = new SingleInstanceApplication();
            app.OnStartup(e);
            return false;
        }

        protected override void OnStartupNextInstance(StartupNextInstanceEventArgs eventArgs)
        {
            // Subsequent launches
            base.OnStartupNextInstance(eventArgs);
            app.Activate();
        }
    }

	public class SingleInstanceApplication
	{
		SEC.Nanoeye.NanoeyeSEM.MiniSEM fr;
		public void OnStartup(Microsoft.VisualBasic.ApplicationServices.StartupEventArgs e)
		{
           

			//base.OnStartup(e);
			SEC.Nanoeye.NanoeyeSEM.Initialize.Splash.Default = new SEC.Nanoeye.NanoeyeSEM.Initialize.Splash();
			SEC.Nanoeye.NanoeyeSEM.Initialize.Splash.Default.Show();



			string logPath = Application.CommonAppDataPath + @".\Log";

			logPath += "\\";
					logPath += DateTime.Now.Year.ToString("00") + "-";
			logPath += DateTime.Now.Month.ToString("00") + "-";

			logPath += DateTime.Now.Day.ToString("00");
			logPath += ".log";
			SEC.GenericSupport.Diagnostics.Helper.LogerInit(logPath);


			SEC.Nanoeye.NanoeyeSEM.AppDeviceEnum ade = SEC.Nanoeye.NanoeyeSEM.AppDeviceEnum.AutoDetect;
			SEC.Nanoeye.NanoeyeSEM.AppSellerEnum ase = SEC.Nanoeye.NanoeyeSEM.AppSellerEnum.SEC;
            // Debug(AppModeEnum.Debug), Run(AppModeEnum.Run) 모드설정
            // 모드설정에 따라서 NanoeyeSEM->Initialize->Initializer.cs 설정필요
            // SearchController()에서 모드에 맞게 주석처리해야함.
            SEC.Nanoeye.NanoeyeSEM.AppModeEnum ame = SEC.Nanoeye.NanoeyeSEM.AppModeEnum.Run;

//#if DEBUG
//#else
//            SEC.Nanoeye.NanoeyeSEM.AppModeEnum ame = SEC.Nanoeye.NanoeyeSEM.AppModeEnum.Run;
//#endif

            SEC.Nanoeye.NanoeyeSEM.Initialize.Splash.Default.UpdateInfo(ade, ase, ame);

			// Create and show the application's main window
			fr = new SEC.Nanoeye.NanoeyeSEM.MiniSEM(ade, ase, ame);

			System.Threading.Thread.CurrentThread.Name = this.ToString();

			Application.Run(fr);

			SEC.GenericSupport.Diagnostics.Helper.LogerExit();
		}

		public void Activate()
		{
			// Reactivate application's main window
			this.fr.Activate();
			this.fr.WindowState = FormWindowState.Normal;
		}
	}

}
