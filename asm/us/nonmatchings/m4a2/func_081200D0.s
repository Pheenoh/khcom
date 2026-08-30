.syntax unified
	.align 2, 0
	.global func_081200D0
	.thumb
	.thumb_func
	.type func_081200D0, %function
func_081200D0: @ 081200D0
	push {r4, r5, r6, lr}
	add sp, #-0x004
	adds r5, r0, #0x0
	ldr r1, _08120198 @ =0x04000084
	movs r0, #0x8F
	strh r0, [r1, #0x00]
	ldr r3, _0812019C @ =0x04000080
	movs r2, #0x00
	strh r2, [r3, #0x00]
	ldr r0, _081201A0 @ =0x04000063
	movs r1, #0x08
	strb r1, [r0, #0x00]
	adds r0, #0x06
	strb r1, [r0, #0x00]
	adds r0, #0x10
	strb r1, [r0, #0x00]
	subs r0, #0x14
	movs r1, #0x80
	strb r1, [r0, #0x00]
	adds r0, #0x08
	strb r1, [r0, #0x00]
	adds r0, #0x10
	strb r1, [r0, #0x00]
	subs r0, #0x0D
	strb r2, [r0, #0x00]
	movs r0, #0x77
	strb r0, [r3, #0x00]
	ldr r0, _081201A4 @ =0x03007FF0
	ldr r4, [r0, #0x00]
	ldr r6, [r4, #0x00]
	ldr r0, _081201A8 @ =0x68736D53
	cmp r6, r0
	bne _08120190
	adds r0, r6, #0x1
	str r0, [r4, #0x00]
	ldr r1, _081201AC @ =0x0203D800
	ldr r0, _081201B0 @ =0x08121149
	str r0, [r1, #0x20]
	ldr r0, _081201B4 @ =0x0811FD19
	str r0, [r1, #0x44]
	ldr r0, _081201B8 @ =0x0811FD2D
	str r0, [r1, #0x4C]
	ldr r0, _081201BC @ =0x081212A1
	str r0, [r1, #0x70]
	ldr r0, _081201C0 @ =0x0811FCA5
	str r0, [r1, #0x74]
	ldr r0, _081201C4 @ =0x0812030D
	str r0, [r1, #0x78]
	ldr r0, _081201C8 @ =0x0811FA29
	str r0, [r1, #0x7C]
	adds r2, r1, #0x0
	adds r2, #0x80
	ldr r0, _081201CC @ =0x08120775
	str r0, [r2, #0x00]
	adds r1, #0x84
	ldr r0, _081201D0 @ =0x0812083D
	str r0, [r1, #0x00]
	str r5, [r4, #0x1C]
	ldr r0, _081201D4 @ =0x08120A55
	str r0, [r4, #0x28]
	ldr r0, _081201D8 @ =0x08120999
	str r0, [r4, #0x2C]
	ldr r0, _081201DC @ =0x081208F1
	str r0, [r4, #0x30]
	ldr r0, _081201E0 @ =0x00000050
	movs r1, #0x00
	strb r0, [r4, #0x0C]
	str r1, [sp, #0x000]
	ldr r2, _081201E4 @ =0x05000040
	mov r0, sp
	adds r1, r5, #0x0
	bl func_08117FE8
	movs r0, #0x01
	strb r0, [r5, #0x01]
	movs r0, #0x11
	strb r0, [r5, #0x1C]
	adds r1, r5, #0x0
	adds r1, #0x41
	movs r0, #0x02
	strb r0, [r1, #0x00]
	adds r1, #0x1B
	movs r0, #0x22
	strb r0, [r1, #0x00]
	adds r1, #0x25
	movs r0, #0x03
	strb r0, [r1, #0x00]
	adds r1, #0x1B
	movs r0, #0x44
	strb r0, [r1, #0x00]
	adds r1, #0x24
	movs r0, #0x04
	strb r0, [r1, #0x01]
	movs r0, #0x88
	strb r0, [r1, #0x1C]
	str r6, [r4, #0x00]
_08120190:
	add sp, #0x004
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_08120198: .4byte 0x04000084
_0812019C: .4byte 0x04000080
_081201A0: .4byte 0x04000063
_081201A4: .4byte 0x03007FF0
_081201A8: .4byte 0x68736D53
_081201AC: .4byte 0x0203D800
_081201B0: .4byte 0x08121149
_081201B4: .4byte 0x0811FD19
_081201B8: .4byte 0x0811FD2D
_081201BC: .4byte 0x081212A1
_081201C0: .4byte 0x0811FCA5
_081201C4: .4byte func_0812030C
_081201C8: .4byte func_0811FA28
_081201CC: .4byte 0x08120775
_081201D0: .4byte func_0812083C
_081201D4: .4byte 0x08120A55
_081201D8: .4byte 0x08120999
_081201DC: .4byte 0x081208F1
_081201E0: .4byte 0x00000050
_081201E4: .4byte 0x05000040
	.byte 0x2A, 0xDF, 0x70, 0x47
.syntax divided
