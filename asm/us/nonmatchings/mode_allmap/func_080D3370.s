.syntax unified
	.align 2, 0
	.global func_080D3370
	.thumb
	.thumb_func
	.type func_080D3370, %function
func_080D3370: @ 080D3370
	push {r4, r5, lr}
	movs r0, #0x0A
	movs r1, #0x01
	bl func_080062F4
	ldr r5, _080D3398 @ =0x05000140
	ldr r4, _080D339C @ =0x02034E40
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	movs r2, #0x10
	bl func_08117FE8
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	movs r2, #0x20
	bl func_08005BE8
	pop {r4, r5}
	pop {r0}
	bx r0
_080D3398: .4byte 0x05000140
_080D339C: .4byte 0x02034E40
.syntax divided
