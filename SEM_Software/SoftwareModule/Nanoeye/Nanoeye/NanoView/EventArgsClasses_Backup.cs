using System;
using System.Runtime.InteropServices;

namespace SEC.Nanoeye.NanoView
{
	internal class NanoviewEventArgs : EventArgs, IComparable
	{
		public readonly NanoeyeDevices device;
		public readonly NanoeyeDeviceType type;
		public readonly UInt32 value;

		private NanoviewEventArgs() { }
		public NanoviewEventArgs(NanoeyeDevices dev, NanoeyeDeviceType type, UInt32 val)
		{
			this.device = dev;
			this.type = type;
			this.value = val;
		}

		#region IComparable ���

		public int CompareTo(object obj)
		{
			if (!(obj is NanoviewEventArgs)) {
				throw new ArgumentException();
			}

			NanoviewEventArgs nea = obj as NanoviewEventArgs;

			UInt16 myAddr = (ushort)((UInt16)device | (UInt16)type);
			UInt16 objAddr = (ushort)((UInt16)nea.device | (UInt16)nea.type);

			return (Int16)myAddr - (Int16)objAddr;
		}

		#endregion

		public override bool Equals(object obj)
		{
			if (obj == null) { return false; }
			if (GetType() != obj.GetType()) { return false; }

			NanoviewEventArgs nea = obj as NanoviewEventArgs;

			if (nea.device != device) { return false; }
			if (nea.type != type) { return false; }
			return true;

		}

		public override int GetHashCode()
		{
			return ((UInt16)device | (UInt16)type);
		}

		public static bool operator ==(NanoviewEventArgs obj1, NanoviewEventArgs obj2)
		{
			return obj1.Equals(obj2);
		}

		public static bool operator !=(NanoviewEventArgs obj1, NanoviewEventArgs obj2)
		{
			return !obj1.Equals(obj2);
		}
	}

	internal class NanoviewErrorEventArgs : EventArgs, IComparable
	{
		public readonly NanoeyeDevices device;
		public readonly NanoeyeDeviceType type;
		public readonly UInt32 value;
		public readonly string message;

		private NanoviewErrorEventArgs() { }
		public NanoviewErrorEventArgs(NanoeyeDevices dev, NanoeyeDeviceType type, UInt32 val, string msg)
		{
			this.device = dev;
			this.type = type;
			this.value = val;
			this.message = msg;
		}

		#region IComparable ���

		public int CompareTo(object obj)
		{
			if ( !(obj is NanoviewErrorEventArgs) )
			{
				throw new ArgumentException();
			}

			NanoviewErrorEventArgs nea = obj as NanoviewErrorEventArgs;

			UInt16 myAddr = (ushort)((UInt16)device | (UInt16)type);
			UInt16 objAddr = (ushort)((UInt16)nea.device | (UInt16)nea.type);

			return (Int16)myAddr - (Int16)objAddr;
		}

		#endregion

		public override bool Equals(object obj)
		{
			if ( obj == null ) { return false; }
			if ( GetType() != obj.GetType() ) { return false; }

			NanoviewErrorEventArgs nea = obj as NanoviewErrorEventArgs;

			if ( nea.device != device ) { return false; }
			if ( nea.type != type ) { return false; }
			return true;

		}

		public override int GetHashCode()
		{
			return ((UInt16)device | (UInt16)type);
		}

		public static bool operator ==(NanoviewErrorEventArgs obj1, NanoviewErrorEventArgs obj2)
		{
			return obj1.Equals(obj2);
		}

		public static bool operator !=(NanoviewErrorEventArgs obj1, NanoviewErrorEventArgs obj2)
		{
			return !obj1.Equals(obj2);
		}
	}

	///// <summary>
	///// Controller���� RepeatRead �̺�Ʈ�� �˸��� ���� delegate
	///// </summary>
	///// <param name="sender">�߻� ��ü</param>
	///// <param name="value">���� ��</param>
	//[ComVisible(false)]
	//[CLSCompliant(true)]
	//public delegate void StringEventHandler(object sender, string value);

	/// <summary>
	/// Controller���� RepeatRead �̺�Ʈ�� �˸��� ���� delegate
	/// </summary>
	/// <param name="sender">�߻� ��ü</param>
	/// <param name="value">���� ��</param>
	[ComVisible(false)]
	[CLSCompliant(true)]
	public delegate void ObjectArrayEventHandler(object sender, object[] value);

	/// <summary>
	/// Controller���� ����� ���� �Ͽ����� �˸�.
	/// </summary>
	/// <param name="sender">�߻� ��ü</param>
	/// <param name="board">�����</param>
	/// <param name="obj">IControlValue ��ü</param>
	[ComVisible(false)]
	[CLSCompliant(true)]
	public delegate void CommunicationErrorEventHandler(object sender, string board, object obj, string message);

	//[ComVisible(false)]
	//[CLSCompliant(true)]
	//public delegate void ColumnEventHandlerInt(object sender, int value, int max, int min, int offset);

	//[ComVisible(false)]
	//[CLSCompliant(true)]
	//public delegate void ColumnEventHandlerDouble(object sender, double value, double max, double min, double offset);

	/// <summary>
	/// Controller�� Ư�� ���� �ٲ������ �˸��� ���� event�� delegate
	/// </summary>
	/// <typeparam name="T">�ڷ� ��</typeparam>
	/// <param name="sender">�̺�Ʈ �߻� ��ü</param>
	/// <param name="value">��</param>
	/// <param name="max">�ִ밪</param>
	/// <param name="min">�ּҰ�</param>
	/// <param name="offset">offset</param>
	[ComVisible(false)]
	[CLSCompliant(true)]
	public delegate void ColumnEventHandler<T>(object sender, T value, T max, T min, T offset);

	/// <summary>
	/// COM���� Column Value(Integer) Change Event �ùķ��̼��� ���� Class. 
	/// Event ����� ���� �� Interface�� ����ϴ� Class�� ���� �ϸ� ��.
	/// </summary>
	[Guid("F2AED0CB-DDF3-4401-8A5E-3E87F6CB0B51"),
	InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
	public interface IColumnEventInt
	{
		/// <summary>
		/// �̺�Ʈ�� ������ method
		/// </summary>
		/// <param name="sender">�̺�Ʈ �߻� ��ü</param>
		/// <param name="value">��</param>
		/// <param name="max">�ִ밪</param>
		/// <param name="min">�ּҰ�</param>
		/// <param name="offset">offset</param>
		void EventFired(object sender, int value, int max, int min, int offset);
	}

	/// <summary>
	/// COM���� Column Value(double) Change Event �ùķ��̼��� ���� Class. 
	/// Event ����� ���� �� Interface�� ����ϴ� Class�� ���� �ϸ� ��.
	/// </summary>
	[Guid("3B89161E-9B87-470d-A953-AA56E6A03D6A"),
	InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
	public interface IColumnEventDouble
	{
		/// <summary>
		/// �̺�Ʈ�� ������ method
		/// </summary>
		/// <param name="sender">�̺�Ʈ �߻� ��ü</param>
		/// <param name="value">��</param>
		/// <param name="max">�ִ밪</param>
		/// <param name="min">�ּҰ�</param>
		/// <param name="offset">offset</param>
		void EventFired(object sender, double value, double max, double min, double offset);
	}

	///// <summary>
	///// COM���� Repeated Read Event �ùķ��̼��� ���� Class. 
	///// Event ����� ���� �� Interface�� ����ϴ� Class�� ���� �ϸ� ��.
	///// </summary>
	//[Guid("DBC4EE18-0010-4f5f-9AEE-76726212EDC3"),
	//InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
	//public interface IStringEvent
	//{
	//    /// <summary>
	//    /// �̺�Ʈ�� ������ method
	//    /// </summary>
	//    /// <param name="sender">�̺�Ʈ �߻� ��ü</param>
	//    /// <param name="value">�̺�Ʈ ��.</param>
	//    void EventFired(object sender, string value);
	//}

	/// <summary>
	/// COM���� Repeated Read Event �ùķ��̼��� ���� Class. 
	/// Event ����� ���� �� Interface�� ����ϴ� Class�� ���� �ϸ� ��.
	/// </summary>
	[Guid("A0AA467B-5768-4dbd-A786-6379745A4571"),
	InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
	public interface IObjectArrayEvent
	{
		/// <summary>
		/// �̺�Ʈ�� ������ method
		/// </summary>
		/// <param name="sender">�̺�Ʈ �߻� ��ü</param>
		/// <param name="value">�̺�Ʈ ��.</param>
		void EventFired(object sender, object[] value);
	}

	/// <summary>
	/// COM���� Commnunication Error Event �ùķ��̼��� ���� Class. 
	/// Event ����� ���� �� Interface�� ����ϴ� Class�� ���� �ϸ� ��.
	/// </summary>
	[Guid("F8BC84D5-68B6-4f9a-B3FE-EB21CFCA217C"),
	InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
	public interface ICommunicationErrorEvent
	{
		/// <summary>
		/// Event�� ������ Method
		/// </summary>
		/// <param name="board">��ſ� ������ ���� ��</param>
		/// <param name="obj">��ſ� ������ IControlValue</param>
		void EventFired(string board, object obj, string message);
	}
}
