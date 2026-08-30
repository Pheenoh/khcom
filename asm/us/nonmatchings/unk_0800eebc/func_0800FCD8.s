.syntax unified
	.align 2, 0
	.global func_0800FCD8
	.thumb
	.thumb_func
	.type func_0800FCD8, %function
func_0800FCD8: @ 0800FCD8
	push {r4, lr}
	adds r2, r0, #0x0
	cmp r2, #0x1E
	bhi _0800FCEC
	ldr r4, _0800FCE8 @ =0x02039BB0
	movs r0, #0x80
	lsls r0, r0, #0x02
	b _0800FCF4
_0800FCE8: .4byte 0x02039BB0
_0800FCEC:
	subs r2, #0x1F
	ldr r4, _0800FD14 @ =0x02039BB0
	movs r0, #0x82
	lsls r0, r0, #0x02
_0800FCF4:
	adds r4, r4, r0
	movs r0, #0x01
	movs r1, #0x00
	bl _0811D57C
	ldr r2, [r4, #0x00]
	ldr r3, [r4, #0x04]
	ands r2, r0
	ands r3, r1
	adds r0, r3, #0x0
	orrs r0, r2
	cmp r0, #0x00
	bne _0800FD18
	movs r0, #0x00
	b _0800FD1A
	.byte 0x00, 0x00
_0800FD14: .4byte 0x02039BB0
_0800FD18:
	movs r0, #0x01
_0800FD1A:
	pop {r4}
	pop {r1}
	bx r1
.syntax divided
