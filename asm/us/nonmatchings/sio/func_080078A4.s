.syntax unified
	.align 2, 0
	.global func_080078A4
	.thumb
	.thumb_func
	.type func_080078A4, %function
func_080078A4: @ 080078A4
	push {r4, lr}
	bl func_08007874
	ldr r4, _080078D8 @ =0x04000208
	movs r0, #0x00
	strh r0, [r4, #0x00]
	bl func_08006C24
	bl func_08006CD4
	bl func_08006CF4
	ldr r1, _080078DC @ =0x04000200
	ldr r2, _080078E0 @ =0x00002001
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	ldr r1, _080078E4 @ =0x04000004
	movs r0, #0x08
	strh r0, [r1, #0x00]
	movs r0, #0x01
	strh r0, [r4, #0x00]
	bl func_08006E74
	pop {r4}
	pop {r0}
	bx r0
_080078D8: .4byte 0x04000208
_080078DC: .4byte 0x04000200
_080078E0: .4byte 0x00002001
_080078E4: .4byte 0x04000004
	.byte 0x02, 0x48, 0x40, 0x78, 0x04, 0x28, 0x03, 0xD0, 0x00, 0x20, 0x02, 0xE0, 0x30, 0x98, 0x03, 0x02
	.byte 0x01, 0x20, 0x70, 0x47
.syntax divided
