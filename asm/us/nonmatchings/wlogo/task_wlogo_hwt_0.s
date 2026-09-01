.syntax unified
	.align 2, 0
	.global task_wlogo_hwt_0
	.thumb
	.thumb_func
	.type task_wlogo_hwt_0, %function
task_wlogo_hwt_0: @ 080B4AE4
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r1, _080B4B2C @ =0x096FAD64
	movs r0, #0x00
	movs r2, #0x20
	bl LoadBgPalette
	ldr r1, _080B4B30 @ =0x09633144
	movs r2, #0xC2
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl LoadBgTiles
	ldr r1, _080B4B34 @ =0x096B7C64
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl LoadBgMap
	movs r1, #0x00
	movs r0, #0x00
	strh r0, [r4, #0x00]
	strh r0, [r4, #0x02]
	strb r1, [r4, #0x04]
	strb r1, [r4, #0x05]
	movs r1, #0x10
	movs r2, #0x00
	bl SetBgBlend
	ldr r0, _080B4B38 @ =0x02034C38
	movs r1, #0x04
	bl TaskPoolInit
	pop {r4}
	pop {r0}
	bx r0
_080B4B2C: .4byte 0x096FAD64
_080B4B30: .4byte 0x09633144
_080B4B34: .4byte 0x096B7C64
_080B4B38: .4byte 0x02034C38
.syntax divided
