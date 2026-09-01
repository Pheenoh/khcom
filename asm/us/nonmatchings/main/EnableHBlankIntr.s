.syntax unified
	.align 2, 0
	.global EnableHBlankIntr
	.thumb
	.thumb_func
	.type EnableHBlankIntr, %function
EnableHBlankIntr: @ 080002D4
	ldr r3, _080002F4 @ =0x04000208
	movs r0, #0x00
	strh r0, [r3, #0x00]
	ldr r2, _080002F8 @ =0x04000200
	ldrh r0, [r2, #0x00]
	movs r1, #0x02
	orrs r0, r1
	strh r0, [r2, #0x00]
	ldr r2, _080002FC @ =0x04000004
	ldrh r0, [r2, #0x00]
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r2, #0x00]
	movs r0, #0x01
	strh r0, [r3, #0x00]
	bx lr
_080002F4: .4byte 0x04000208
_080002F8: .4byte 0x04000200
_080002FC: .4byte 0x04000004
.syntax divided
