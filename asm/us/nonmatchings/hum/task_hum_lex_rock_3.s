.syntax unified
	.align 2, 0
	.global task_hum_lex_rock_3
	.thumb
	.thumb_func
	.type task_hum_lex_rock_3, %function
task_hum_lex_rock_3: @ 08057AA0
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	movs r1, #0xAE
	lsls r1, r1, #0x02
	adds r0, r5, r1
	ldr r0, [r0, #0x00]
	bl ReleaseObjTiles
	movs r1, #0xAF
	lsls r1, r1, #0x02
	adds r0, r5, r1
	ldr r0, [r0, #0x00]
	bl ReleaseObjPalette
	movs r0, #0xB2
	lsls r0, r0, #0x01
	adds r6, r5, r0
	ldrh r0, [r6, #0x00]
	cmp r0, #0x00
	beq _08057AEA
	ldr r0, [r5, #0x30]
	bl ReleaseObjPalette
	movs r4, #0x00
	ldrh r6, [r6, #0x00]
	cmp r4, r6
	bge _08057AEA
	movs r1, #0xB2
	lsls r1, r1, #0x01
	adds r6, r5, r1
_08057ADC:
	ldm r5!, {r0}
	bl ReleaseObjTiles
	adds r4, #0x01
	ldrh r0, [r6, #0x00]
	cmp r4, r0
	blt _08057ADC
_08057AEA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.syntax divided
