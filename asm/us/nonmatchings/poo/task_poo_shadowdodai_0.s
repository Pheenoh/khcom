.syntax unified
	.align 2, 0
	.global task_poo_shadowdodai_0
	.thumb
	.thumb_func
	.type task_poo_shadowdodai_0, %function
task_poo_shadowdodai_0: @ 080CBF6C
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r2, [r1, #0x00]
	str r2, [r4, #0x14]
	ldr r0, [r1, #0x04]
	str r0, [r4, #0x18]
	ldr r0, [r2, #0x00]
	str r0, [r4, #0x00]
	ldr r0, [r2, #0x04]
	str r0, [r4, #0x04]
	ldr r0, _080CBFBC @ =0x08B22BBC
	movs r1, #0x80
	lsls r1, r1, #0x01
	bl func_080026A4
	str r0, [r4, #0x08]
	ldr r0, _080CBFC0 @ =0x08F69BE4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x0C]
	adds r5, r4, #0x0
	adds r5, #0x1C
	ldr r1, _080CBFC4 @ =0x09EE1384
	ldr r2, _080CBFC8 @ =0x09EE1380
	adds r0, r5, #0x0
	bl func_08005968
	adds r0, r5, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl func_080059A4
	adds r0, r5, #0x0
	bl func_08005A64
	str r0, [r4, #0x10]
	pop {r4, r5}
	pop {r0}
	bx r0
_080CBFBC: .4byte 0x08B22BBC
_080CBFC0: .4byte 0x08F69BE4
_080CBFC4: .4byte 0x09EE1384
_080CBFC8: .4byte 0x09EE1380
.syntax divided
