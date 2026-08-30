.syntax unified
	.align 2, 0
	.global func_080D313C
	.thumb
	.thumb_func
	.type func_080D313C, %function
func_080D313C: @ 080D313C
	push {r4, lr}
	movs r0, #0x02
	bl func_08005130
	adds r3, r0, #0x0
	adds r3, #0x20
	ldr r2, _080D3164 @ =0x02039BB0
	ldr r0, [r2, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _080D316C
	movs r0, #0x0E
	ldsb r0, [r2, r0]
	lsls r1, r0, #0x02
	adds r1, r1, r0
	lsls r1, r1, #0x06
	ldr r0, _080D3168 @ =0x097B8258
	b _080D3178
	.byte 0x00, 0x00
_080D3164: .4byte 0x02039BB0
_080D3168: .4byte 0x097B8258
_080D316C:
	movs r0, #0x0E
	ldsb r0, [r2, r0]
	lsls r1, r0, #0x02
	adds r1, r1, r0
	lsls r1, r1, #0x06
	ldr r0, _080D31BC @ =0x097B7218
_080D3178:
	adds r4, r1, r0
	movs r2, #0xA0
	lsls r2, r2, #0x01
	adds r0, r4, #0x0
	adds r1, r3, #0x0
	bl func_080043B4
	movs r0, #0x02
	bl func_0800514C
	movs r1, #0x90
	lsls r1, r1, #0x03
	adds r3, r0, r1
	ldr r4, _080D31C0 @ =0x0983BC18
	adds r0, r4, #0x0
	adds r1, r3, #0x0
	movs r2, #0x0A
	bl func_080043B4
	movs r0, #0x02
	bl func_0800514C
	movs r1, #0x98
	lsls r1, r1, #0x03
	adds r3, r0, r1
	adds r4, #0x40
	adds r0, r4, #0x0
	adds r1, r3, #0x0
	movs r2, #0x0A
	bl func_080043B4
	pop {r4}
	pop {r0}
	bx r0
_080D31BC: .4byte 0x097B7218
_080D31C0: .4byte 0x0983BC18
.syntax divided
