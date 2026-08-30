.syntax unified
	.align 2, 0
	.global task_allmap_bar_0
	.thumb
	.thumb_func
	.type task_allmap_bar_0, %function
task_allmap_bar_0: @ 080D3F60
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, _080D3FBC @ =0x0203C460
	str r4, [r0, #0x00]
	ldr r0, _080D3FC0 @ =0x0976D8A6
	movs r1, #0xB0
	lsls r1, r1, #0x02
	bl func_080026A4
	str r0, [r4, #0x00]
	ldr r0, _080D3FC4 @ =0x0976DBDA
	movs r1, #0xC0
	bl func_080026A4
	str r0, [r4, #0x04]
	ldr r0, _080D3FC8 @ =0x0984A1D8
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x08]
	movs r2, #0x00
	movs r1, #0x00
	movs r0, #0x10
	strh r0, [r4, #0x0C]
	str r1, [r4, #0x28]
	ldr r0, _080D3FCC @ =0xFFFFF800
	str r0, [r4, #0x10]
	movs r0, #0xA0
	lsls r0, r0, #0x08
	str r0, [r4, #0x18]
	ldr r0, _080D3FD0 @ =0xFFFF8000
	str r0, [r4, #0x20]
	str r1, [r4, #0x14]
	movs r0, #0x98
	lsls r0, r0, #0x08
	str r0, [r4, #0x1C]
	str r1, [r4, #0x24]
	adds r0, r4, #0x0
	adds r0, #0x2C
	strb r2, [r0, #0x00]
	adds r4, #0x2D
	strb r2, [r4, #0x00]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D3FBC: .4byte 0x0203C460
_080D3FC0: .4byte 0x0976D8A6
_080D3FC4: .4byte 0x0976DBDA
_080D3FC8: .4byte 0x0984A1D8
_080D3FCC: .4byte 0xFFFFF800
_080D3FD0: .4byte 0xFFFF8000
.syntax divided
