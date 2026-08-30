.syntax unified
	.align 2, 0
	.global func_080D8308
	.thumb
	.thumb_func
	.type func_080D8308, %function
func_080D8308: @ 080D8308
	ldr r0, _080D8338 @ =0x02034F04
	ldr r2, [r0, #0x00]
	movs r1, #0x98
	lsls r1, r1, #0x03
	adds r0, r2, r1
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x00]
	lsls r0, r1, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r2, r2, r0
	movs r0, #0x90
	lsls r0, r0, #0x01
	adds r2, r2, r0
	ldrh r0, [r2, #0x00]
	subs r0, #0x08
	lsls r0, r0, #0x10
	cmp r0, #0x00
	ble _080D833C
	lsrs r0, r0, #0x10
	b _080D833E
	.byte 0x00, 0x00
_080D8338: .4byte 0x02034F04
_080D833C:
	movs r0, #0x00
_080D833E:
	bx lr
.syntax divided
