#pragma once
#include "B4RDefines.h"
#include "IRremote.h"
namespace B4R {
	//~Version: 1.00
	//~Shortname: IrResult
	class IrResult {
		public:
			Int DecodeType;
			ULong Value;
			#define /*Int UNKNOWN;*/ IrResult_UNKNOWN -1 
			#define /*Int RC5;*/ IrResult_RC5 1 
			#define /*Int RC6;*/ IrResult_RC6 2 
			#define /*Int NEC;*/ IrResult_NEC 3 
			#define /*Int SONY;*/ IrResult_SONY 4 
			#define /*Int PANASONIC;*/ IrResult_PANASONIC 5 
			#define /*Int JVC;*/ IrResult_JVC 6 
			#define /*Int SAMSUNG;*/ IrResult_SAMSUNG 7 
			#define /*Int WHYNTER;*/ IrResult_WHYNTER 8 
			#define /*Int AIWA_RC_T501;*/ IrResult_AIWA_RC_T501 9 
			#define /*Int LG;*/ IrResult_LG 10 
			#define /*Int SANYO;*/ IrResult_SANYO 11 
			#define /*Int MITSUBISHI;*/ IrResult_MITSUBISHI 12 
			#define /*Int DISH;*/ IrResult_DISH 13 
			#define /*Int SHARP;*/ IrResult_SHARP 14 
			#define /*Int DENON;*/ IrResult_DENON 15 
			#define /*Int PRONTO;*/ IrResult_PRONTO 16 
			#define /*Int LEGO_PF;*/ IrResult_LEGO_PF 17 
	};
	typedef void (*SubVoidIrResult)(IrResult* Result) ;
	//~ShortName: IrReceive
	//~Event: Decoded (Result As IrResult)
	class IrReceive { 
		private:
			uint8_t backend[sizeof(IRrecv)];
			PollerNode pnode;
			static void looper(void* b);
			SubVoidIrResult DecodedSub;
		public:
			//~hide
			IRrecv* ir;
			//Initializes the object.
			//Pin - The ir receiver pin.
			//DecodedSub - The sub that will handle the decoded event.
			void Initialize(Byte Pin, SubVoidIrResult DecodedSub);
			//Enables the receiver.
			void Enable();
	};
	//~Shortname: IrSend
	class IrSend {
		private:
			IRsend ir;
		public:
			//KHZ - Modulation frequency. Should be between 36 to 40.
			void Enable(Int KHZ);
			void  SendRC5 (ULong data,  Int nbits) ;
			void  SendRC6 (ULong data,  Int nbits) ;
			void  SendNEC (ULong data,  Int nbits) ;
			void  SendSony(ULong data,  Int nbits) ;
			void  SendPanasonic(UInt address,  ULong data) ;
			void  SendJVC (ULong data,  Int nbits,  bool repeat) ;
			void  SendSAMSUNG (ULong data,  Int nbits) ;
			void  SendWhynter (ULong data,  Int nbits) ;
			void  SendAiwaRCT501 (Int code) ;
			void  SendLG(ULong data,  Int nbits) ;
			void  SendDISH (ULong data,  Int nbits) ;
			void  SendSharpRaw  (ULong data,  Int nbits) ;
			void  SendSharp (UInt address,  UInt command) ;
			void  SendDenon  (ULong data,  Int nbits) ;
			void  SendLegoPowerFunctions (UInt data, bool repeat) ;
	};
}
