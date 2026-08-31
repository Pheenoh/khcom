.syntax unified
	.align 2, 0
	.global func_0807C33C
	.thumb
	.thumb_func
	.type func_0807C33C, %function
func_0807C33C: @ 0807C33C
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	ldr r6, [r5, #0x78]
	movs r0, #0x02
	ands r6, r0
	cmp r6, #0x00
	beq _0807C378
	movs r0, #0x00
	str r0, [r5, #0x00]
	str r0, [r5, #0x14]
	str r0, [r5, #0x18]
	ldr r2, _0807C374 @ =0x08F709B0
	adds r0, r5, #0x0
	adds r0, #0x46
	ldrb r1, [r0, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r2, #0x10
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
	movs r1, #0xA0
	lsls r1, r1, #0x02
	bl LoadObjTiles
	str r0, [r5, #0x04]
	b _0807C394
	.byte 0x00, 0x00
_0807C374: .4byte 0x08F709B0
_0807C378:
	ldr r1, [r5, #0x48]
	ldr r0, [r1, #0x04]
	ldr r4, [r1, #0x08]
	movs r1, #0x80
	lsls r1, r1, #0x02
	bl LoadObjTiles
	str r0, [r5, #0x00]
	adds r0, r4, #0x0
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r5, #0x14]
	str r6, [r5, #0x04]
_0807C394:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
