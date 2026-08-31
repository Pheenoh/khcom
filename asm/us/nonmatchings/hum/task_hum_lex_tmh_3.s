.syntax unified
	.align 2, 0
	.global task_hum_lex_tmh_3
	.thumb
	.thumb_func
	.type task_hum_lex_tmh_3, %function
task_hum_lex_tmh_3: @ 08057270
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x40]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x44]
	bl ReleaseObjPalette
	ldr r0, [r4, #0x00]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x04]
	bl ReleaseObjPalette
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
