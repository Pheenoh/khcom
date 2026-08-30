.syntax unified
	.align 2, 0
	.global func_0800FD20
	.thumb
	.thumb_func
	.type func_0800FD20, %function
func_0800FD20: @ 0800FD20
	push {r4, lr}
	adds r2, r0, #0x0
	cmp r2, #0x1E
	bhi _0800FD34
	ldr r4, _0800FD30 @ =0x02039BB0
	movs r0, #0x8E
	lsls r0, r0, #0x01
	b _0800FD3C
_0800FD30: .4byte 0x02039BB0
_0800FD34:
	subs r2, #0x1F
	ldr r4, _0800FD5C @ =0x02039BB0
	movs r0, #0x92
	lsls r0, r0, #0x01
_0800FD3C:
	adds r4, r4, r0
	movs r0, #0x01
	movs r1, #0x00
	bl __ashldi3
	ldr r2, [r4, #0x00]
	ldr r3, [r4, #0x04]
	ands r2, r0
	ands r3, r1
	adds r0, r3, #0x0
	orrs r0, r2
	cmp r0, #0x00
	bne _0800FD60
	movs r0, #0x00
	b _0800FD62
	.byte 0x00, 0x00
_0800FD5C: .4byte 0x02039BB0
_0800FD60:
	movs r0, #0x01
_0800FD62:
	pop {r4}
	pop {r1}
	bx r1
.syntax divided
