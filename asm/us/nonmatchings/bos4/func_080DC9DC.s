.syntax unified
	.align 2, 0
	.global func_080DC9DC
	.thumb
	.thumb_func
	.type func_080DC9DC, %function
func_080DC9DC: @ 080DC9DC
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0x0
	adds r6, r1, #0x0
	adds r7, r2, #0x0
	adds r5, r3, #0x0
	ldr r0, _080DCA18 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0xCC
	movs r2, #0xFE
	lsls r2, r2, #0x01
	adds r1, r5, r2
	ldr r0, [r0, #0x00]
	ldr r1, [r1, #0x00]
	adds r0, r0, r1
	str r0, [r4, #0x00]
	movs r1, #0x9F
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080DCA2C
	bl func_080DC510
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080DCA20
	ldr r0, [r4, #0x00]
	ldr r2, _080DCA1C @ =0xFFFFDE00
	adds r0, r0, r2
	b _080DCA48
_080DCA18: .4byte 0x02039B84
_080DCA1C: .4byte 0xFFFFDE00
_080DCA20:
	ldr r0, [r4, #0x00]
	ldr r1, _080DCA28 @ =0xFFFFCA00
	b _080DCA46
	.byte 0x00, 0x00
_080DCA28: .4byte 0xFFFFCA00
_080DCA2C:
	bl func_080DC510
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080DCA40
	ldr r0, [r4, #0x00]
	movs r2, #0xD8
	lsls r2, r2, #0x06
	adds r0, r0, r2
	b _080DCA48
_080DCA40:
	ldr r0, [r4, #0x00]
	movs r1, #0x88
	lsls r1, r1, #0x06
_080DCA46:
	adds r0, r0, r1
_080DCA48:
	str r0, [r4, #0x00]
	ldr r1, _080DCA74 @ =0x02039B84
	ldr r0, [r1, #0x00]
	adds r0, #0xD0
	ldr r0, [r0, #0x00]
	str r0, [r6, #0x00]
	ldr r2, [r1, #0x00]
	adds r2, #0xD4
	movs r1, #0x80
	lsls r1, r1, #0x02
	adds r0, r5, r1
	ldr r1, [r0, #0x00]
	movs r0, #0xA0
	lsls r0, r0, #0x07
	adds r1, r1, r0
	ldr r0, [r2, #0x00]
	adds r0, r0, r1
	str r0, [r7, #0x00]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080DCA74: .4byte 0x02039B84
.syntax divided
