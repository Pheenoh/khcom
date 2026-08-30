.syntax unified
	.align 2, 0
	.global func_080EF3A0
	.thumb
	.thumb_func
	.type func_080EF3A0, %function
func_080EF3A0: @ 080EF3A0
	push {r4, r5, r6, lr}
	adds r3, r0, #0x0
	adds r4, r3, #0x0
	adds r4, #0x08
	ldr r0, _080EF3F0 @ =0x02039BA0
	ldr r5, [r0, #0x00]
	ldr r2, [r5, #0x00]
	ldr r1, _080EF3F4 @ =0xFFFFE800
	adds r0, r2, r1
	ldr r1, [r3, #0x08]
	cmp r1, r0
	blt _080EF3DC
	movs r6, #0x84
	lsls r6, r6, #0x09
	adds r0, r2, r6
	cmp r1, r0
	bgt _080EF3DC
	ldr r0, [r4, #0x04]
	ldr r1, [r4, #0x08]
	adds r2, r0, r1
	ldr r1, [r5, #0x04]
	ldr r4, _080EF3F8 @ =0xFFFFF800
	adds r0, r1, r4
	cmp r2, r0
	blt _080EF3DC
	movs r6, #0xC0
	lsls r6, r6, #0x08
	adds r0, r1, r6
	cmp r2, r0
	ble _080EF3FC
_080EF3DC:
	adds r0, r3, #0x0
	adds r0, #0xCC
	movs r1, #0x00
	str r1, [r0, #0x00]
	subs r0, #0x84
	movs r1, #0x01
	bl func_08012614
	movs r0, #0x01
	b _080EF3FE
_080EF3F0: .4byte 0x02039BA0
_080EF3F4: .4byte 0xFFFFE800
_080EF3F8: .4byte 0xFFFFF800
_080EF3FC:
	movs r0, #0x00
_080EF3FE:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.syntax divided
