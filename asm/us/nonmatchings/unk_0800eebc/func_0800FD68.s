.syntax unified
	.align 2, 0
	.global func_0800FD68
	.thumb
	.thumb_func
	.type func_0800FD68, %function
func_0800FD68: @ 0800FD68
	push {r4, lr}
	adds r2, r0, #0x0
	cmp r2, #0x48
	bne _0800FD90
	ldr r3, _0800FD8C @ =0x02039BB0
	movs r1, #0x8E
	lsls r1, r1, #0x01
	adds r0, r3, r1
	movs r1, #0x00
	movs r2, #0x00
	str r1, [r0, #0x00]
	str r2, [r0, #0x04]
	movs r4, #0x92
	lsls r4, r4, #0x01
	adds r0, r3, r4
	str r1, [r0, #0x00]
	str r2, [r0, #0x04]
	b _0800FDC6
_0800FD8C: .4byte 0x02039BB0
_0800FD90:
	cmp r2, #0x1E
	bhi _0800FDA4
	ldr r4, _0800FDA0 @ =0x02039BB0
	movs r0, #0x8E
	lsls r0, r0, #0x01
	adds r4, r4, r0
	b _0800FDAE
	.byte 0x00, 0x00
_0800FDA0: .4byte 0x02039BB0
_0800FDA4:
	subs r2, #0x1F
	ldr r4, _0800FDCC @ =0x02039BB0
	movs r1, #0x92
	lsls r1, r1, #0x01
	adds r4, r4, r1
_0800FDAE:
	movs r0, #0x01
	movs r1, #0x00
	bl _0811D57C
	mvns r0, r0
	mvns r1, r1
	ldr r2, [r4, #0x00]
	ldr r3, [r4, #0x04]
	ands r2, r0
	ands r3, r1
	str r2, [r4, #0x00]
	str r3, [r4, #0x04]
_0800FDC6:
	pop {r4}
	pop {r0}
	bx r0
_0800FDCC: .4byte 0x02039BB0
.syntax divided
