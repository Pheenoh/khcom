.syntax unified
	.align 2, 0
	.global func_0800FBCC
	.thumb
	.thumb_func
	.type func_0800FBCC, %function
func_0800FBCC: @ 0800FBCC
	push {r4, lr}
	adds r2, r0, #0x0
	cmp r2, #0x1E
	bhi _0800FBE0
	ldr r4, _0800FBDC @ =0x02039BB0
	movs r0, #0x86
	lsls r0, r0, #0x01
	b _0800FBE8
_0800FBDC: .4byte 0x02039BB0
_0800FBE0:
	subs r2, #0x1F
	ldr r4, _0800FC08 @ =0x02039BB0
	movs r0, #0x8A
	lsls r0, r0, #0x01
_0800FBE8:
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
	bne _0800FC0C
	movs r0, #0x00
	b _0800FC0E
	.byte 0x00, 0x00
_0800FC08: .4byte 0x02039BB0
_0800FC0C:
	movs r0, #0x01
_0800FC0E:
	pop {r4}
	pop {r1}
	bx r1
.syntax divided
