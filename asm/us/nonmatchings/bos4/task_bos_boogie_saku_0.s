.syntax unified
	.align 2, 0
	.global task_bos_boogie_saku_0
	.thumb
	.thumb_func
	.type task_bos_boogie_saku_0, %function
task_bos_boogie_saku_0: @ 080DA75C
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	str r1, [r6, #0x24]
	ldr r0, _080DA7B0 @ =0x09799CBA
	movs r1, #0xB8
	lsls r1, r1, #0x02
	bl func_080026A4
	str r0, [r6, #0x00]
	ldr r0, _080DA7B4 @ =0x0984AF78
	movs r1, #0x20
	bl func_08002A14
	str r0, [r6, #0x04]
	adds r4, r6, #0x0
	adds r4, #0x08
	ldr r1, _080DA7B8 @ =0x09EF680C
	ldr r2, _080DA7BC @ =0x09EF67FC
	adds r0, r4, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x00
	bl func_080059A4
	movs r5, #0x00
	movs r4, #0x00
	strh r4, [r6, #0x20]
	adds r0, r6, #0x0
	adds r0, #0x28
	movs r1, #0x01
	bl func_08000E64
	str r4, [r6, #0x3C]
	adds r0, r6, #0x0
	adds r0, #0x40
	strb r5, [r0, #0x00]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080DA7B0: .4byte 0x09799CBA
_080DA7B4: .4byte 0x0984AF78
_080DA7B8: .4byte 0x09EF680C
_080DA7BC: .4byte 0x09EF67FC
.syntax divided
