.syntax unified
	.align 2, 0
	.global task_poo_cabbage_0
	.thumb
	.thumb_func
	.type task_poo_cabbage_0, %function
task_poo_cabbage_0: @ 080D10E0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0x0
	ldr r0, _080D119C @ =0x00098300
	str r0, [r7, #0x24]
	ldr r0, _080D11A0 @ =0x0004D100
	str r0, [r7, #0x28]
	movs r6, #0x00
	str r6, [r7, #0x2C]
	adds r1, r7, #0x0
	adds r1, #0xC4
	ldr r0, _080D11A4 @ =0x000004CC
	str r0, [r1, #0x00]
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x0F
	ands r0, r1
	adds r0, #0x58
	adds r1, r7, #0x0
	adds r1, #0xC8
	strb r0, [r1, #0x00]
	subs r1, #0x08
	movs r0, #0xE6
	lsls r0, r0, #0x01
	str r0, [r1, #0x00]
	str r6, [r7, #0x04]
	adds r4, r7, #0x0
	adds r4, #0x0C
	ldr r1, _080D11A8 @ =0x09EF6060
	ldr r2, _080D11AC @ =0x09EF602C
	adds r0, r4, #0x0
	bl AnimInit
	adds r1, r7, #0x0
	adds r1, #0xA4
	movs r0, #0x00
	mov r8, r0
	movs r0, #0x02
	strh r0, [r1, #0x00]
	adds r0, r4, #0x0
	movs r1, #0x02
	movs r2, #0x01
	bl AnimStart
	adds r0, r4, #0x0
	bl AnimGetGfx
	str r0, [r7, #0x08]
	adds r4, #0x38
	adds r0, r4, #0x0
	movs r1, #0x0A
	movs r2, #0x08
	movs r3, #0x10
	bl func_080122AC
	ldr r1, [r7, #0x24]
	ldr r2, [r7, #0x28]
	ldr r3, [r7, #0x2C]
	adds r0, r4, #0x0
	bl func_08012324
	adds r0, r7, #0x0
	adds r0, #0xD0
	movs r5, #0x01
	strb r5, [r0, #0x00]
	adds r4, #0x64
	adds r0, r4, #0x0
	movs r1, #0x02
	bl TaskPoolInit
	adds r1, r7, #0x0
	adds r1, #0x24
	adds r0, r4, #0x0
	movs r2, #0x80
	bl func_080CC178
	adds r0, r7, #0x0
	adds r0, #0xBC
	str r6, [r0, #0x00]
	adds r0, #0x12
	strh r6, [r0, #0x00]
	adds r0, #0x03
	mov r1, r8
	strb r1, [r0, #0x00]
	adds r0, #0x01
	strb r5, [r0, #0x00]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080D119C: .4byte 0x00098300
_080D11A0: .4byte 0x0004D100
_080D11A4: .4byte 0x000004CC
_080D11A8: .4byte 0x09EF6060
_080D11AC: .4byte 0x09EF602C
.syntax divided
