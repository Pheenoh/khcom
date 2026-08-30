.syntax unified
	.align 2, 0
	.global task_poo_mapbutterfly_0
	.thumb
	.thumb_func
	.type task_poo_mapbutterfly_0, %function
task_poo_mapbutterfly_0: @ 080D2630
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r0, [r1, #0x00]
	str r0, [r4, #0x24]
	ldr r0, [r1, #0x04]
	str r0, [r4, #0x28]
	movs r0, #0x00
	str r0, [r4, #0x2C]
	ldr r1, _080D2680 @ =0x09760986
	movs r0, #0x40
	bl func_080028F8
	str r0, [r4, #0x00]
	ldr r0, _080D2684 @ =0x09849E58
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x04]
	adds r5, r4, #0x0
	adds r5, #0x0C
	ldr r1, _080D2688 @ =0x09EF6298
	ldr r2, _080D268C @ =0x09EF6208
	adds r0, r5, #0x0
	bl func_08005968
	adds r0, r5, #0x0
	movs r1, #0x00
	movs r2, #0x00
	bl func_080059A4
	adds r0, r5, #0x0
	bl func_08005AFC
	str r0, [r4, #0x08]
	adds r4, #0x34
	movs r0, #0x01
	strb r0, [r4, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
_080D2680: .4byte 0x09760986
_080D2684: .4byte 0x09849E58
_080D2688: .4byte 0x09EF6298
_080D268C: .4byte 0x09EF6208
.syntax divided
