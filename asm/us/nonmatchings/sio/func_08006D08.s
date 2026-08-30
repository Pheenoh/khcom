.syntax unified
	.align 2, 0
	.global func_08006D08
	.thumb
	.thumb_func
	.type func_08006D08, %function
func_08006D08: @ 08006D08
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	add sp, #-0x004
	ldr r0, _08006DDC @ =0x0203406E
	mov r8, r0
	ldr r5, _08006DE0 @ =0x04000208
	ldrh r2, [r5, #0x00]
	movs r4, #0x00
	strh r4, [r5, #0x00]
	ldr r6, _08006DE4 @ =0x04000200
	ldrh r1, [r6, #0x00]
	ldr r0, _08006DE8 @ =0x0000FF3F
	ands r0, r1
	strh r0, [r6, #0x00]
	strh r2, [r5, #0x00]
	ldr r0, _08006DEC @ =0x04000134
	strh r4, [r0, #0x00]
	ldr r2, _08006DF0 @ =0x04000128
	movs r1, #0x80
	lsls r1, r1, #0x06
	adds r0, r1, #0x0
	strh r0, [r2, #0x00]
	ldrh r0, [r2, #0x00]
	ldr r3, _08006DF4 @ =0x00004003
	adds r1, r3, #0x0
	orrs r0, r1
	strh r0, [r2, #0x00]
	ldrh r0, [r5, #0x00]
	mov r1, r8
	strh r0, [r1, #0x00]
	ldr r0, _08006DF8 @ =0x08000661
	bl func_08006BFC
	ldr r0, _08006DFC @ =0x080073B5
	bl func_08006CC8
	ldr r0, _08006E00 @ =0x080073A5
	bl func_08006CE8
	strh r4, [r5, #0x00]
	ldrh r0, [r6, #0x00]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r6, #0x00]
	mov r3, r8
	ldrh r0, [r3, #0x00]
	strh r0, [r5, #0x00]
	ldr r0, _08006E04 @ =0x0400012A
	strh r4, [r0, #0x00]
	ldr r2, _08006E08 @ =0x04000120
	movs r0, #0x00
	movs r1, #0x00
	str r0, [r2, #0x00]
	str r1, [r2, #0x04]
	movs r5, #0x00
	str r5, [sp, #0x000]
	ldr r1, _08006E0C @ =0x02039830
	ldr r2, _08006E10 @ =0x050000C9
	mov r0, sp
	bl func_08117FE8
	ldr r0, _08006E14 @ =0x02034070
	strb r4, [r0, #0x00]
	ldr r0, _08006E18 @ =0x02034071
	strb r4, [r0, #0x00]
	ldr r0, _08006E1C @ =0x02034073
	strb r4, [r0, #0x00]
	ldr r0, _08006E20 @ =0x020397D0
	strb r4, [r0, #0x00]
	ldr r0, _08006E24 @ =0x02039800
	strb r4, [r0, #0x00]
	ldr r0, _08006E28 @ =0x02039820
	str r5, [r0, #0x00]
	ldr r0, _08006E2C @ =0x020397D4
	strh r5, [r0, #0x00]
	ldr r0, _08006E30 @ =0x020397F0
	str r5, [r0, #0x00]
	ldr r0, _08006E34 @ =0x02039828
	str r5, [r0, #0x00]
	ldr r0, _08006E38 @ =0x020397FC
	strb r4, [r0, #0x00]
	ldr r0, _08006E3C @ =0x02039824
	strb r4, [r0, #0x00]
	ldr r0, _08006E40 @ =0x0203982C
	strb r4, [r0, #0x00]
	ldr r0, _08006E44 @ =0x02039B60
	strb r4, [r0, #0x00]
	ldr r0, _08006E48 @ =0x02034074
	strb r4, [r0, #0x00]
	ldr r0, _08006E4C @ =0x0203406C
	strb r4, [r0, #0x00]
	ldr r0, _08006E50 @ =0x02034076
	strh r5, [r0, #0x00]
	ldr r0, _08006E54 @ =0x02034078
	strh r5, [r0, #0x00]
	ldr r0, _08006E58 @ =0x02039804
	str r5, [r0, #0x00]
	ldr r0, _08006E5C @ =0x020397F8
	str r5, [r0, #0x00]
	add sp, #0x004
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_08006DDC: .4byte 0x0203406E
_08006DE0: .4byte 0x04000208
_08006DE4: .4byte 0x04000200
_08006DE8: .4byte 0x0000FF3F
_08006DEC: .4byte 0x04000134
_08006DF0: .4byte 0x04000128
_08006DF4: .4byte 0x00004003
_08006DF8: .4byte 0x08000661
_08006DFC: .4byte 0x080073B5
_08006E00: .4byte 0x080073A5
_08006E04: .4byte 0x0400012A
_08006E08: .4byte 0x04000120
_08006E0C: .4byte 0x02039830
_08006E10: .4byte 0x050000C9
_08006E14: .4byte 0x02034070
_08006E18: .4byte 0x02034071
_08006E1C: .4byte 0x02034073
_08006E20: .4byte 0x020397D0
_08006E24: .4byte 0x02039800
_08006E28: .4byte 0x02039820
_08006E2C: .4byte 0x020397D4
_08006E30: .4byte 0x020397F0
_08006E34: .4byte 0x02039828
_08006E38: .4byte 0x020397FC
_08006E3C: .4byte 0x02039824
_08006E40: .4byte 0x0203982C
_08006E44: .4byte 0x02039B60
_08006E48: .4byte 0x02034074
_08006E4C: .4byte 0x0203406C
_08006E50: .4byte 0x02034076
_08006E54: .4byte 0x02034078
_08006E58: .4byte 0x02039804
_08006E5C: .4byte 0x020397F8
.syntax divided
