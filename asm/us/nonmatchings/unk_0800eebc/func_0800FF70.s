.syntax unified
	.align 2, 0
	.global func_0800FF70
	.thumb
	.thumb_func
	.type func_0800FF70, %function
func_0800FF70: @ 0800FF70
	push {r4, lr}
	adds r2, r0, #0x0
	cmp r2, #0x3F
	bhi _0800FF84
	ldr r4, _0800FF80 @ =0x02039BB0
	movs r0, #0xAA
	lsls r0, r0, #0x01
	b _0800FFB4
_0800FF80: .4byte 0x02039BB0
_0800FF84:
	cmp r2, #0x7F
	bhi _0800FF98
	subs r2, #0x40
	ldr r4, _0800FF94 @ =0x02039BB0
	movs r0, #0xAE
	lsls r0, r0, #0x01
	b _0800FFB4
	.byte 0x00, 0x00
_0800FF94: .4byte 0x02039BB0
_0800FF98:
	cmp r2, #0xBF
	bhi _0800FFAC
	subs r2, #0x80
	ldr r4, _0800FFA8 @ =0x02039BB0
	movs r0, #0xB2
	lsls r0, r0, #0x01
	b _0800FFB4
	.byte 0x00, 0x00
_0800FFA8: .4byte 0x02039BB0
_0800FFAC:
	subs r2, #0xC0
	ldr r4, _0800FFD4 @ =0x02039BB0
	movs r0, #0xB6
	lsls r0, r0, #0x01
_0800FFB4:
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
	bne _0800FFD8
	movs r0, #0x00
	b _0800FFDA
	.byte 0x00, 0x00
_0800FFD4: .4byte 0x02039BB0
_0800FFD8:
	movs r0, #0x01
_0800FFDA:
	pop {r4}
	pop {r1}
	bx r1
.syntax divided
