.syntax unified
	.align 2, 0
	.global task_bos_ursula_tako_0
	.thumb
	.thumb_func
	.type task_bos_ursula_tako_0, %function
task_bos_ursula_tako_0: @ 080DCA98
	push {r4, r5, r6, lr}
	add sp, #-0x010
	adds r6, r0, #0x0
	ldrb r0, [r1, #0x00]
	movs r1, #0x9F
	lsls r1, r1, #0x01
	adds r5, r6, r1
	movs r1, #0x00
	strb r0, [r5, #0x00]
	movs r2, #0xFE
	lsls r2, r2, #0x01
	adds r0, r6, r2
	str r1, [r0, #0x00]
	adds r2, #0x04
	adds r0, r6, r2
	str r1, [r0, #0x00]
	add r1, sp, #0x008
	add r2, sp, #0x00C
	add r0, sp, #0x004
	adds r3, r6, #0x0
	bl func_080DC9DC
	adds r0, r6, #0x0
	adds r0, #0x28
	ldr r1, _080DCB08 @ =0x096FE1A8
	ldr r2, [sp, #0x004]
	ldr r3, [sp, #0x008]
	ldr r4, [sp, #0x00C]
	str r4, [sp, #0x000]
	bl func_0801B37C
	movs r1, #0xCE
	lsls r1, r1, #0x01
	adds r0, r6, r1
	movs r1, #0x07
	movs r2, #0x28
	movs r3, #0x20
	bl func_080122AC
	ldrb r0, [r5, #0x00]
	cmp r0, #0x00
	beq _080DCB14
	ldr r0, _080DCB0C @ =0x0000FFFC
	strh r0, [r6, #0x24]
	ldr r0, [r6, #0x5C]
	ldr r1, [r6, #0x60]
	movs r2, #0x04
	movs r3, #0x00
	orrs r0, r2
	str r0, [r6, #0x5C]
	str r1, [r6, #0x60]
	movs r2, #0xFC
	lsls r2, r2, #0x01
	adds r1, r6, r2
	ldr r0, _080DCB10 @ =0xFFFFD800
	b _080DCB20
_080DCB08: .4byte 0x096FE1A8
_080DCB0C: .4byte 0x0000FFFC
_080DCB10: .4byte 0xFFFFD800
_080DCB14:
	strh r0, [r6, #0x24]
	movs r0, #0xFC
	lsls r0, r0, #0x01
	adds r1, r6, r0
	movs r0, #0xA0
	lsls r0, r0, #0x06
_080DCB20:
	str r0, [r1, #0x00]
	ldr r5, _080DCBBC @ =0x09EF6860
	adds r0, r5, #0x0
	movs r1, #0x06
	bl func_08003524
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080DCBC0 @ =0x0979E344
	bl AllocObjTiles
	str r0, [r6, #0x00]
	ldr r0, _080DCBC4 @ =0x0984B0F8
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r6, #0x04]
	ldr r0, _080DCBC8 @ =0x08F69BC4
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r6, #0x08]
	adds r4, r6, #0x0
	adds r4, #0x0C
	ldr r1, _080DCBCC @ =0x09EF68A0
	adds r0, r4, #0x0
	adds r2, r5, #0x0
	bl AnimInit
	ldrh r1, [r6, #0x24]
	adds r1, #0x04
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0x0
	movs r2, #0x01
	bl AnimStart
	movs r2, #0x9C
	lsls r2, r2, #0x01
	adds r1, r6, r2
	movs r0, #0x00
	str r0, [r1, #0x00]
	movs r0, #0xA0
	lsls r0, r0, #0x01
	adds r4, r6, r0
	movs r1, #0x9F
	lsls r1, r1, #0x01
	adds r0, r6, r1
	ldrb r0, [r0, #0x00]
	bl func_080DCA78
	adds r2, r0, #0x0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0x0
	movs r1, #0x07
	movs r3, #0x01
	bl func_080122AC
	ldr r1, [r6, #0x2C]
	ldr r2, [r6, #0x30]
	movs r0, #0x80
	lsls r0, r0, #0x05
	adds r2, r2, r0
	ldr r3, _080DCBD0 @ =0xFFFFC800
	adds r0, r4, #0x0
	bl func_08012324
	adds r0, r6, #0x0
	adds r0, #0x28
	movs r1, #0x23
	movs r2, #0x33
	bl func_0801C7FC
	add sp, #0x010
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080DCBBC: .4byte 0x09EF6860
_080DCBC0: .4byte 0x0979E344
_080DCBC4: .4byte 0x0984B0F8
_080DCBC8: .4byte 0x08F69BC4
_080DCBCC: .4byte 0x09EF68A0
_080DCBD0: .4byte 0xFFFFC800
.syntax divided
