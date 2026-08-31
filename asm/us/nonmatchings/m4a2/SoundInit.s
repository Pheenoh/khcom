.syntax unified
	.align 2, 0
	.global SoundInit
	.thumb
	.thumb_func
	.type SoundInit, %function
SoundInit: @ 08120214
	push {r4, r5, lr}
	add sp, #-0x004
	adds r5, r0, #0x0
	movs r3, #0x00
	str r3, [r5, #0x00]
	ldr r1, _081202CC @ =0x040000C4
	ldr r0, [r1, #0x00]
	movs r2, #0x80
	lsls r2, r2, #0x12
	ands r0, r2
	cmp r0, #0x00
	beq _08120230
	ldr r0, _081202D0 @ =0x84400004
	str r0, [r1, #0x00]
_08120230:
	ldr r1, _081202D4 @ =0x040000D0
	ldr r0, [r1, #0x00]
	ands r0, r2
	cmp r0, #0x00
	beq _0812023E
	ldr r0, _081202D0 @ =0x84400004
	str r0, [r1, #0x00]
_0812023E:
	ldr r0, _081202D8 @ =0x040000C6
	movs r2, #0x80
	lsls r2, r2, #0x03
	adds r1, r2, #0x0
	strh r1, [r0, #0x00]
	adds r0, #0x0C
	strh r1, [r0, #0x00]
	ldr r1, _081202DC @ =0x04000084
	movs r0, #0x8F
	strh r0, [r1, #0x00]
	subs r1, #0x02
	ldr r2, _081202E0 @ =0x0000A90E
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	ldr r2, _081202E4 @ =0x04000089
	ldrb r1, [r2, #0x00]
	movs r0, #0x3F
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2, #0x00]
	ldr r1, _081202E8 @ =0x040000BC
	movs r2, #0xD4
	lsls r2, r2, #0x02
	adds r0, r5, r2
	str r0, [r1, #0x00]
	adds r1, #0x04
	ldr r0, _081202EC @ =0x040000A0
	str r0, [r1, #0x00]
	adds r1, #0x08
	movs r2, #0x98
	lsls r2, r2, #0x04
	adds r0, r5, r2
	str r0, [r1, #0x00]
	adds r1, #0x04
	ldr r0, _081202F0 @ =0x040000A4
	str r0, [r1, #0x00]
	ldr r0, _081202F4 @ =0x03007FF0
	str r5, [r0, #0x00]
	str r3, [sp, #0x000]
	ldr r2, _081202F8 @ =0x050003EC
	mov r0, sp
	adds r1, r5, #0x0
	bl CpuSet
	movs r0, #0x08
	strb r0, [r5, #0x06]
	movs r0, #0x0F
	strb r0, [r5, #0x07]
	ldr r0, _081202FC @ =0x0811FAA5
	str r0, [r5, #0x38]
	ldr r0, _08120300 @ =0x081213C1
	str r0, [r5, #0x28]
	str r0, [r5, #0x2C]
	str r0, [r5, #0x30]
	str r0, [r5, #0x3C]
	ldr r4, _08120304 @ =0x0203D800
	adds r0, r4, #0x0
	bl func_0811F5E8
	str r4, [r5, #0x34]
	movs r0, #0x80
	lsls r0, r0, #0x0B
	bl func_0812030C
	ldr r0, _08120308 @ =0x68736D53
	str r0, [r5, #0x00]
	add sp, #0x004
	pop {r4, r5}
	pop {r0}
	bx r0
_081202CC: .4byte 0x040000C4
_081202D0: .4byte 0x84400004
_081202D4: .4byte 0x040000D0
_081202D8: .4byte 0x040000C6
_081202DC: .4byte 0x04000084
_081202E0: .4byte 0x0000A90E
_081202E4: .4byte 0x04000089
_081202E8: .4byte 0x040000BC
_081202EC: .4byte 0x040000A0
_081202F0: .4byte 0x040000A4
_081202F4: .4byte 0x03007FF0
_081202F8: .4byte 0x050003EC
_081202FC: .4byte 0x0811FAA5
_08120300: .4byte 0x081213C1
_08120304: .4byte 0x0203D800
_08120308: .4byte 0x68736D53
.syntax divided
