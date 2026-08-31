.syntax unified
	.align 2, 0
	.global task_bos_dsd_main_3
	.thumb
	.thumb_func
	.type task_bos_dsd_main_3, %function
task_bos_dsd_main_3: @ 080C26A0
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x0C]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x10]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x4C]
	bl ReleaseObjPalette
	ldr r0, [r4, #0x50]
	bl ReleaseObjPalette
	ldr r0, [r4, #0x00]
	movs r1, #0xD8
	lsls r1, r1, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x00]
	movs r1, #0xD9
	lsls r1, r1, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl ReleaseObjPalette
	ldr r0, [r4, #0x00]
	movs r1, #0xDA
	lsls r1, r1, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x00]
	movs r1, #0xDB
	lsls r1, r1, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl ReleaseObjPalette
	ldr r0, [r4, #0x00]
	movs r1, #0xDC
	lsls r1, r1, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl ReleaseObjPalette
	ldr r0, [r4, #0x00]
	movs r1, #0xDD
	lsls r1, r1, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x00]
	movs r1, #0xDE
	lsls r1, r1, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl ReleaseObjPalette
	adds r0, r4, #0x0
	adds r0, #0xB4
	bl func_08012304
	adds r4, #0x58
	adds r0, r4, #0x0
	bl TaskPoolDestroy
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
