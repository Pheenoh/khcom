.syntax unified
	.align 2, 0
	.global mode_jiminy_2
	.thumb
	.thumb_func
	.type mode_jiminy_2, %function
mode_jiminy_2: @ 0805C910
	push {r4, lr}
	bl func_08065940
	ldr r4, _0805C9B0 @ =0x02034934
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x04]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x08]
	bl ReleaseObjPalette
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x0C]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x10]
	bl ReleaseObjPalette
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x14]
	bl ReleaseObjPalette
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x18]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x1C]
	bl ReleaseObjPalette
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x20]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x24]
	bl ReleaseObjPalette
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x28]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x2C]
	bl ReleaseObjPalette
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x30]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x34]
	bl ReleaseObjPalette
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x38]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x3C]
	bl ReleaseObjPalette
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x40]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x44]
	bl ReleaseObjPalette
	bl func_0805A484
	ldr r0, [r4, #0x00]
	bl EwramFree
	pop {r4}
	pop {r0}
	bx r0
_0805C9B0: .4byte 0x02034934
.syntax divided
