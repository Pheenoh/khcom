.syntax unified
	.align 2, 0
	.global func_080D3008
	.thumb
	.thumb_func
	.type func_080D3008, %function
func_080D3008: @ 080D3008
	push {r4, lr}
	movs r4, #0x00
_080D300C:
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
	adds r4, #0x01
	cmp r4, #0x1F
	ble _080D300C
	movs r0, #0x0A
	movs r1, #0x00
	bl func_080062F4
	movs r0, #0x00
	movs r1, #0x10
	movs r2, #0x10
	bl func_08006238
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
