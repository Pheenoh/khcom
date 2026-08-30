.syntax unified
	.align 2, 0
	.global func_080B895C
	.thumb
	.thumb_func
	.type func_080B895C, %function
func_080B895C: @ 080B895C
	push {lr}
	movs r2, #0x94
	lsls r2, r2, #0x01
	adds r1, r0, r2
	movs r2, #0x00
	strb r2, [r1, #0x00]
	movs r3, #0x91
	lsls r3, r3, #0x02
	adds r1, r0, r3
	strb r2, [r1, #0x00]
	movs r1, #0xD7
	lsls r1, r1, #0x02
	adds r2, r0, r1
	ldr r1, _080B89A4 @ =0x09EF397C
	ldr r1, [r1, #0x00]
	str r1, [r2, #0x00]
	movs r3, #0x8F
	lsls r3, r3, #0x03
	adds r2, r0, r3
	ldr r1, _080B89A8 @ =0x09EF3960
	ldr r1, [r1, #0x00]
	str r1, [r2, #0x00]
	ldr r2, [r0, #0x00]
	ldr r1, [r2, #0x08]
	str r1, [r2, #0x14]
	ldr r1, [r2, #0x0C]
	str r1, [r2, #0x18]
	ldr r1, [r2, #0x10]
	ldr r3, _080B89AC @ =0xFFFFEB00
	adds r1, r1, r3
	str r1, [r2, #0x1C]
	bl func_080B8418
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080B89A4: .4byte 0x09EF397C
_080B89A8: .4byte 0x09EF3960
_080B89AC: .4byte 0xFFFFEB00
.syntax divided
