.syntax unified
	.align 2, 0
	.global func_0800ABD8
	.thumb
	.thumb_func
	.type func_0800ABD8, %function
func_0800ABD8: @ 0800ABD8
	ldr r2, _0800AC1C @ =0x09ECEB50
	ldr r0, [r2, #0x00]
	movs r1, #0x00
	strb r1, [r0, #0x00]
	ldr r0, [r2, #0x00]
	strb r1, [r0, #0x01]
	ldr r0, [r2, #0x00]
	movs r3, #0x00
	strh r1, [r0, #0x02]
	strb r3, [r0, #0x04]
	ldr r1, [r2, #0x00]
	ldr r0, _0800AC20 @ =0x02039BB0
	adds r0, #0xF8
	ldrh r0, [r0, #0x00]
	strh r0, [r1, #0x06]
	ldr r2, _0800AC24 @ =0x03006C10
	ldr r0, [r2, #0x00]
	movs r1, #0x02
	negs r1, r1
	ands r0, r1
	str r0, [r2, #0x00]
	ldr r1, _0800AC28 @ =0x02039B90
	movs r0, #0x98
	strh r0, [r1, #0x00]
	ldr r1, _0800AC2C @ =0x02039B88
	movs r2, #0xB0
	lsls r2, r2, #0x01
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	ldr r1, _0800AC30 @ =0x02039B8C
	adds r2, #0x42
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	bx lr
_0800AC1C: .4byte 0x09ECEB50
_0800AC20: .4byte 0x02039BB0
_0800AC24: .4byte 0x03006C10
_0800AC28: .4byte 0x02039B90
_0800AC2C: .4byte 0x02039B88
_0800AC30: .4byte 0x02039B8C
.syntax divided
