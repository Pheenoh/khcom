.syntax unified
	.align 2, 0
	.global task_poo_spark_0
	.thumb
	.thumb_func
	.type task_poo_spark_0, %function
task_poo_spark_0: @ 080D0920
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldm r1!, {r2, r3, r5}
	stm r0!, {r2, r3, r5}
	ldr r1, [r1, #0x00]
	str r1, [r0, #0x00]
	movs r0, #0x80
	lsls r0, r0, #0x02
	ldr r1, _080D0960 @ =0x098A4B68
	bl AllocObjTiles
	str r0, [r4, #0x28]
	ldr r0, _080D0964 @ =0x08F69BE4
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r4, #0x2C]
	adds r4, #0x10
	ldr r1, _080D0968 @ =0x09EF8CC0
	ldr r2, _080D096C @ =0x09EF8CA0
	adds r0, r4, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl AnimStart
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D0960: .4byte 0x098A4B68
_080D0964: .4byte 0x08F69BE4
_080D0968: .4byte 0x09EF8CC0
_080D096C: .4byte 0x09EF8CA0
.syntax divided
