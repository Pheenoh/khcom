.syntax unified
	.align 2, 0
	.global task_status_bar_0
	.thumb
	.thumb_func
	.type task_status_bar_0, %function
task_status_bar_0: @ 080D7910
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, _080D7960 @ =0x097A18EC
	movs r1, #0xB8
	lsls r1, r1, #0x02
	bl LoadObjTiles
	str r0, [r4, #0x00]
	ldr r0, _080D7964 @ =0x0984B1B8
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r4, #0x04]
	movs r2, #0x00
	movs r1, #0x00
	movs r0, #0x10
	strh r0, [r4, #0x08]
	ldr r0, _080D7968 @ =0x0203C550
	str r1, [r0, #0x00]
	ldr r0, _080D796C @ =0xFFFFF800
	str r0, [r4, #0x0C]
	movs r0, #0xA0
	lsls r0, r0, #0x08
	str r0, [r4, #0x14]
	ldr r0, _080D7970 @ =0xFFFF8000
	str r0, [r4, #0x1C]
	str r1, [r4, #0x10]
	movs r0, #0x98
	lsls r0, r0, #0x08
	str r0, [r4, #0x18]
	str r1, [r4, #0x20]
	adds r0, r4, #0x0
	adds r0, #0x24
	strb r2, [r0, #0x00]
	adds r4, #0x25
	strb r2, [r4, #0x00]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D7960: .4byte 0x097A18EC
_080D7964: .4byte 0x0984B1B8
_080D7968: .4byte 0x0203C550
_080D796C: .4byte 0xFFFFF800
_080D7970: .4byte 0xFFFF8000
.syntax divided
