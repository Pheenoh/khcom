.syntax unified
	.align 2, 0
	.global func_080DD248
	.thumb
	.thumb_func
	.type func_080DD248, %function
func_080DD248: @ 080DD248
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0x0
	adds r6, r1, #0x0
	adds r7, r2, #0x0
	adds r5, r3, #0x0
	ldr r0, _080DD27C @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0xCC
	ldr r0, [r0, #0x00]
	ldr r1, [r5, #0x24]
	adds r0, r0, r1
	str r0, [r4, #0x00]
	adds r0, r5, #0x0
	adds r0, #0x22
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080DD290
	bl func_080DC510
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080DD284
	ldr r0, [r4, #0x00]
	ldr r1, _080DD280 @ =0xFFFFB600
	adds r0, r0, r1
	b _080DD2AC
_080DD27C: .4byte 0x02039B84
_080DD280: .4byte 0xFFFFB600
_080DD284:
	ldr r0, [r4, #0x00]
	ldr r2, _080DD28C @ =0xFFFFA200
	b _080DD2AA
	.byte 0x00, 0x00
_080DD28C: .4byte 0xFFFFA200
_080DD290:
	bl func_080DC510
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080DD2A4
	ldr r0, [r4, #0x00]
	movs r1, #0xBC
	lsls r1, r1, #0x07
	adds r0, r0, r1
	b _080DD2AC
_080DD2A4:
	ldr r0, [r4, #0x00]
	movs r2, #0x94
	lsls r2, r2, #0x07
_080DD2AA:
	adds r0, r0, r2
_080DD2AC:
	str r0, [r4, #0x00]
	ldr r1, _080DD2D8 @ =0x02039B84
	ldr r0, [r1, #0x00]
	adds r0, #0xD0
	ldr r0, [r0, #0x00]
	movs r2, #0x80
	lsls r2, r2, #0x04
	adds r0, r0, r2
	str r0, [r6, #0x00]
	ldr r0, [r1, #0x00]
	adds r0, #0xD4
	ldr r1, [r5, #0x28]
	movs r2, #0xA0
	lsls r2, r2, #0x07
	adds r1, r1, r2
	ldr r0, [r0, #0x00]
	adds r0, r0, r1
	str r0, [r7, #0x00]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080DD2D8: .4byte 0x02039B84
.syntax divided
