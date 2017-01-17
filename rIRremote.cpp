#include "B4RDefines.h"
namespace B4R {
	void IrReceive::Initialize(Byte Pin, SubVoidIrResult DecodedSub) {
		ir = new (backend) IRrecv(Pin);
		this->DecodedSub = DecodedSub;
		FunctionUnion fu;
		fu.PollerFunction = looper;
		pnode.functionUnion = fu;
		pnode.tag = this;
	}
	void IrReceive::Enable() {
		ir->enableIRIn();
		if (pnode.next == NULL) {
			pollers.add(&pnode);
		}
	}
	//static
	void IrReceive::looper(void* b) {
		IrReceive* me = (IrReceive*) b;
		decode_results dr;
		if (me->ir->decode(&dr)) {
			IrResult irRes;
			irRes.DecodeType = dr.decode_type;
			irRes.Value = dr.value;
			me->DecodedSub(&irRes);
			me->ir->resume();
		}
		
	}
	void IrSend::Enable(Int KHZ) {
		pinMode(TIMER_PWM_PIN, OUTPUT);
		ir.enableIROut(KHZ);
	}
	void  IrSend::SendRC5 (ULong data,  Int nbits) {
		ir.sendRC5(data, nbits);
	}
	void  IrSend::SendRC6 (ULong data,  Int nbits) {
		ir.sendRC6(data, nbits);
	}
	void  IrSend::SendNEC (ULong data,  Int nbits) {
		ir.sendNEC(data, nbits);
	}
	void  IrSend::SendSony(ULong data,  Int nbits) {
		ir.sendSony(data, nbits);
	}
	void  IrSend::SendPanasonic(UInt address,  ULong data)  {
		ir.sendPanasonic(address, data);
	}
	void  IrSend::SendJVC (ULong data,  Int nbits,  bool repeat) {
		ir.sendJVC(data, nbits, repeat);
	}
	void  IrSend::SendSAMSUNG (ULong data,  Int nbits) {
		ir.sendSAMSUNG(data, nbits);
	}
	void  IrSend::SendWhynter (ULong data,  Int nbits) {
		ir.sendWhynter(data, nbits);
	}
	void  IrSend::SendAiwaRCT501 (Int code) {
		ir.sendAiwaRCT501(code);
	}
	void  IrSend::SendLG(ULong data,  Int nbits) {
		ir.sendLG(data, nbits);
	}
	void  IrSend::SendDISH (ULong data,  Int nbits) {
		ir.sendDISH(data, nbits);
	}
	void  IrSend::SendSharpRaw  (ULong data,  Int nbits) {
		ir.sendSharpRaw(data, nbits);
	}
	void  IrSend::SendSharp (UInt address,  UInt command) {
		ir.sendSharp(address, command);
	}
	void  IrSend::SendDenon  (ULong data,  Int nbits) {
		ir.sendDenon(data, nbits);
	}
	void  IrSend::SendLegoPowerFunctions (UInt data, bool repeat) {
		ir.sendLegoPowerFunctions(data, repeat);
	}
}