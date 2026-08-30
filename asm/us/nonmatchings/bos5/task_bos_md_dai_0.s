.syntax unified
	.align 2, 0
	.global task_bos_md_dai_0
	.thumb
	.thumb_func
	.type task_bos_md_dai_0, %function
task_bos_md_dai_0: @ 080FD41C
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	ldr r0, _080FD4A0 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r2, [r0, #0x68]
	ldr r3, [r0, #0x6C]
	ldr r4, _080FD4A4 @ =0x00100000
	ldr r5, _080FD4A8 @ =0x00000000
	orrs r2, r4
	str r2, [r0, #0x68]
	str r3, [r0, #0x6C]
	ldr r0, [r1, #0x04]
	str r0, [r6, #0x78]
	adds r2, r6, #0x0
	adds r2, #0x80
	ldr r0, [r1, #0x00]
	str r0, [r2, #0x00]
	adds r0, r6, #0x0
	adds r0, #0x7C
	movs r1, #0x00
	strh r1, [r0, #0x00]
	adds r0, #0x02
	strh r1, [r0, #0x00]
	movs r0, #0x80
	lsls r0, r0, #0x08
	str r0, [r6, #0x00]
	ldr r0, _080FD4AC @ =0x00014F00
	str r0, [r6, #0x04]
	str r1, [r6, #0x08]
	movs r0, #0x14
	strh r0, [r6, #0x10]
	ldr r0, _080FD4B0 @ =0xFFFF6000
	str r0, [r6, #0x0C]
	adds r4, r6, #0x0
	adds r4, #0x1C
	adds r0, r4, #0x0
	movs r1, #0x07
	movs r2, #0x18
	movs r3, #0x18
	bl func_080122AC
	ldr r1, [r6, #0x00]
	ldr r2, [r6, #0x04]
	ldr r3, [r6, #0x08]
	adds r0, r4, #0x0
	bl func_08012324
	adds r0, r4, #0x0
	movs r1, #0x01
	bl func_08012614
	ldr r0, _080FD4B4 @ =0x09A3C9BC
	movs r1, #0x20
	bl func_08002A14
	str r0, [r6, #0x14]
	ldr r0, _080FD4B8 @ =0x09999ED0
	movs r1, #0x90
	lsls r1, r1, #0x03
	bl func_080026A4
	str r0, [r6, #0x18]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080FD4A0: .4byte 0x02039B84
_080FD4A4: .4byte 0x00100000
_080FD4A8: .4byte 0x00000000
_080FD4AC: .4byte 0x00014F00
_080FD4B0: .4byte 0xFFFF6000
_080FD4B4: .4byte 0x09A3C9BC
_080FD4B8: .4byte 0x09999ED0
.syntax divided
