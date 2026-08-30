.syntax unified
	.align 2, 0
	.global func_0800FF00
	.thumb
	.thumb_func
	.type func_0800FF00, %function
func_0800FF00: @ 0800FF00
	push {r4, lr}
	adds r2, r0, #0x0
	cmp r2, #0x3F
	bhi _0800FF14
	ldr r4, _0800FF10 @ =0x02039BB0
	movs r0, #0x9A
	lsls r0, r0, #0x01
	b _0800FF44
_0800FF10: .4byte 0x02039BB0
_0800FF14:
	cmp r2, #0x7F
	bhi _0800FF28
	subs r2, #0x40
	ldr r4, _0800FF24 @ =0x02039BB0
	movs r0, #0x9E
	lsls r0, r0, #0x01
	b _0800FF44
	.byte 0x00, 0x00
_0800FF24: .4byte 0x02039BB0
_0800FF28:
	cmp r2, #0xBF
	bhi _0800FF3C
	subs r2, #0x80
	ldr r4, _0800FF38 @ =0x02039BB0
	movs r0, #0xA2
	lsls r0, r0, #0x01
	b _0800FF44
	.byte 0x00, 0x00
_0800FF38: .4byte 0x02039BB0
_0800FF3C:
	subs r2, #0xC0
	ldr r4, _0800FF64 @ =0x02039BB0
	movs r0, #0xA6
	lsls r0, r0, #0x01
_0800FF44:
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
	bne _0800FF68
	movs r0, #0x00
	b _0800FF6A
	.byte 0x00, 0x00
_0800FF64: .4byte 0x02039BB0
_0800FF68:
	movs r0, #0x01
_0800FF6A:
	pop {r4}
	pop {r1}
	bx r1
.syntax divided
