.syntax unified
	.align 2, 0
	.global task_wlogo_nvl_0
	.thumb
	.thumb_func
	.type task_wlogo_nvl_0, %function
task_wlogo_nvl_0: @ 080B5460
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r1, _080B54C4 @ =0x096FADA4
	movs r0, #0x00
	movs r2, #0x20
	bl LoadBgPalette
	ldr r1, _080B54C8 @ =0x09638664
	movs r2, #0xC4
	lsls r2, r2, #0x03
	movs r0, #0x00
	bl LoadBgTiles
	ldr r1, _080B54CC @ =0x096B8C64
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl LoadBgMap
	ldr r5, _080B54D0 @ =0x09638C84
	movs r0, #0x00
	bl GetBgCharBase
	adds r1, r0, #0x0
	movs r2, #0xD0
	lsls r2, r2, #0x02
	adds r0, r5, #0x0
	bl RequestDma3Copy
	movs r0, #0x00
	movs r1, #0x00
	strh r1, [r4, #0x02]
	strb r0, [r4, #0x00]
	strb r0, [r4, #0x0A]
	strb r0, [r4, #0x04]
	strh r1, [r4, #0x06]
	strh r1, [r4, #0x08]
	movs r0, #0x00
	movs r1, #0x10
	movs r2, #0x00
	bl SetBgBlend
	ldr r0, _080B54D4 @ =0x02034C50
	movs r1, #0x04
	bl TaskPoolInit
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080B54C4: .4byte 0x096FADA4
_080B54C8: .4byte 0x09638664
_080B54CC: .4byte 0x096B8C64
_080B54D0: .4byte 0x09638C84
_080B54D4: .4byte 0x02034C50
.syntax divided
