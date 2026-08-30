.syntax unified
	.align 2, 0
	.global func_0800FC90
	.thumb
	.thumb_func
	.type func_0800FC90, %function
func_0800FC90: @ 0800FC90
	push {r4, lr}
	adds r2, r0, #0x0
	cmp r2, #0x1E
	bhi _0800FCA4
	ldr r4, _0800FCA0 @ =0x02039BB0
	movs r0, #0xF4
	lsls r0, r0, #0x01
	b _0800FCAC
_0800FCA0: .4byte 0x02039BB0
_0800FCA4:
	subs r2, #0x1F
	ldr r4, _0800FCCC @ =0x02039BB0
	movs r0, #0xF8
	lsls r0, r0, #0x01
_0800FCAC:
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
	bne _0800FCD0
	movs r0, #0x00
	b _0800FCD2
	.byte 0x00, 0x00
_0800FCCC: .4byte 0x02039BB0
_0800FCD0:
	movs r0, #0x01
_0800FCD2:
	pop {r4}
	pop {r1}
	bx r1
.syntax divided
